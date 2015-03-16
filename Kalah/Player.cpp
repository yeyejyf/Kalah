//
//  Player.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "Player.h"
#include <iostream>

Player::Player(int player, GameManager& gm,
               const std::string& name):_id(player), mgr(&gm), _name(name){}

bool Player::run(){
    
    std::cout<<"It's " << _name << "'s turn.\n";
    bool playable = true;
    
    while (playable) {
        
        if (mgr->emptyAll(_id)) {
            clear();
            return true;
        }
        
        mgr->printTable(_id);
        int number = 0;
        while (number <= 0 ||number > 6) {
            std::cout << "Please enter the position of house(1~6): ";
            std::cin >> number;
            if (mgr->empty(_id, number - 1)) {
                number = -1;
                std::cout << "You cannot choose an empty house.\n";
                continue;
            }
            std::cout << std::endl;
        }
        int output = mgr->sowSeed(_id, number - 1);
        if (output == 10) {
            std::cout << "Congratulations! You wins!\n";
            return true;
        }
        if (output != 6) {
            playable = false;
            std::cout << _name <<"'s turn is over.\n";
        }else{
            std::cout << "You earn one more chance!\n";
        }
    }
    mgr->printTable(_id);
    std::cout << std::endl;
    
    return false;
}

void Player::clear(){
    std::cout << "You cannot move now.\n";
    int result = mgr->clear(_id);
    if (result == 1) {
        std::cout << "Congratulations! You wins!\n";
    }else if (result == -1){
        std::cout << "You are defeated.\n";
    }else{
        std::cout << "The game ends in a draw.\n";
    }
    std::cout <<std::endl;
}
