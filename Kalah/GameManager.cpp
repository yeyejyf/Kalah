//
//  GameManager.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "GameManager.h"
#include "PlayChess.h"
#include <iostream>
#include <iomanip>
#include <vector>

GameManager::GameManager(int seed):_seed(seed){
    for (int i=0; i<2; i++) {
        std::vector<int> item;
        for (int j=0; j<6; j++) {
            item.push_back(seed);
        }
        item.push_back(0);
        _chess.push_back(item);
    }
    _win = seed * 6;
}

int GameManager::sowSeed(int player, int number){
    return PlayChess::sowSeed(player, number, _chess, _win);
    
}


void GameManager::printTable(int player) const{
    for (int i=0; i<7; i++) {
        std::cout<<std::setw(2)<<_chess[1 - player][6-i];
        if (i != 6) {
            std::cout<<" ";
        }
    }
    std::cout<<std::endl;
    
    std::cout<<"   ";
    for (int i=0; i<7; i++) {
        std::cout<<std::setw(2)<<_chess[player][i];
        if (i != 6) {
            std::cout<<" ";
        }
    }
    std::cout<<std::endl;
    std::cout << "POS:1  2  3  4  5  6  STORE\n";
    
}

bool GameManager::checkWin(int player){
    return _chess[player][6] > _win;
}

bool GameManager::empty(int player, int number){
    return _chess[player][number] == 0;
}
bool GameManager::emptyAll(int player){
    for (int i=0; i<6; i++) {
        if (!empty(player, i)) {
            return false;
        }
    }
    return true;
}

int GameManager::clear(int player){
    int opposite = 1 - player;
    for (int i=0; i<6; i++) {
        _chess[opposite][6] += _chess[opposite][i];
        _chess[opposite][i] = 0;
    }
    if (_chess[opposite][6] > _chess[player][6]) {
        return -1;
    }else if (_chess[opposite][6] < _chess[player][6]){
        return 1;
    }else{
        return 0;
    }
}

std::vector<std::vector<int>> GameManager::getChess() const{
    return _chess;
}

int GameManager::nSeeds(int player, int number){
    return _chess[player][number];
}

int GameManager::getSeedCount() const{
    return _seed;
}

// Only for the use of test
void GameManager::fakeChess(int p[2][7]){
    for (int i=0; i<2; i++) {
        for (int j=0; j<=6; j++) {
            _chess[i][j] = p[i][j];
        }
    }
}





