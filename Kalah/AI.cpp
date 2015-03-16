//
//  AI.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "AI.h"
#include <iostream>

AI::AI(int player, GameManager& gm, std::string name):_id(player), mgr(&gm), _name(name){}

bool AI::run(){
    
    std::cout << "It's "<< _name <<"'s turn.\n";
    bool playable = true;
    
    while (playable) {
        
        if (mgr->emptyAll(_id)) {
            clear();
            return true;
        }
        
        mgr->printTable( 1 - _id);
        
        int pos = chooseHouse();
        
        if (pos < 0) {
            return false;
        }
        
        int output = mgr->sowSeed(_id, pos);
        
        if (output == 10) {
            mgr->printTable(1 - _id);
            std::cout << "You are defeated.\n";
            return true;
        }
        
        if (output != 6) {
            playable = false;
            std::cout << _name <<"'s turn is over.\n";
        }else{
            std::cout << _name << " earns one more chance.\n";
        }
        
    }
    
    mgr->printTable(1 - _id);
    std::cout << std::endl;
    
    return false;
}

int AI::chooseHouse(){
    int pos = oneMoreChance();
    if (pos >= 0) {
        return pos;
    }
    std::vector<int> list = findAvailable();
    if (list.size()<=1) {
        return list[0];
    }
    std::vector<int> earned;
    for (int pos: list) {
        int tmp = mgr->nSeeds(_id, pos);
        if (tmp + pos > 6) {
            earned.push_back(-1);
        }else if (mgr->nSeeds(_id, tmp+pos) == 0) {
            earned.push_back(mgr->nSeeds(1-_id, tmp+pos)+1);
        }else{
            earned.push_back(0);
        }
    }
    int max = -1, loc = -1;
    for (int k=0; k < earned.size(); k++) {
        if (earned[k] > max) {
            max = earned[k];
            loc = k;
        }
    }
    if (loc>-1) {
        return list[loc];
    }else{
        return list[0];
    }
}

int AI::oneMoreChance(){
    
    for (int i = 5; i >= 0; i--) {
        if (mgr->nSeeds(_id, i) + i == 6) {
            return i;
        }
    }
    
    return -1;
}

std::vector<int> AI::findAvailable(){
    std::vector<int> list;
    for (int i=0; i<6; i++) {
        if (!mgr->empty(_id, i)) {
            list.push_back(i);
        }
    }
    return list;
}

void AI::clear(){
    std::cout << "AI cannot move now.\n";
    int result = mgr->clear(_id);
    if (result == -1) {
        std::cout << "Congratulations! You wins!\n";
    }else if (result == 1){
        std::cout << "You are defeated.\n";
    }else{
        std::cout << "The game ends in a draw.\n";
    }
    std::cout <<std::endl;
    
}