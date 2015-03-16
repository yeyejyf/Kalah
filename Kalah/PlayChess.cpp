//
//  PlayChess.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "PlayChess.h"

int PlayChess::sowSeed(int player, int number, std::vector<std::vector<int>>& chess, int win){
    
    int count = chess[player][number];
    chess[player][number] = 0;
    int current = number;
    
    while (count > 0) {
        current ++;
        if (current == 7) {
            current = -1;
            count = sowOpposite(player, count, chess);
        }else{
            chess[player][current] ++;
            count --;
        }
    }
    
    if (current >= 0 && current <= 5) {
        captureOpposite(player, current, chess);
    }
    
    if (chess[player][6] > win) {
        return 10;
    }
    
    return current;

}

void PlayChess::captureOpposite(int player, int current, std::vector<std::vector<int>>& chess){
    if (chess[player][current] != 1) {
        return;
    }
    int opp_chess = chess[1-player][5-current];
    chess[1-player][5-current] = 0;
    chess[player][current] = 0;
    chess[player][6] += opp_chess + 1;
    
}

int PlayChess::sowOpposite(int player, int count, std::vector<std::vector<int>>& chess){
    int opposite = 1 - player;
    if (count <= 6) {
        for (int i = 0; i < count ; i ++) {
            chess[opposite][i] ++;
        }
        return 0;
    }else{
        for (int i = 0; i < 6; i ++) {
            chess[opposite][i] ++;
        }
        return count - 6;
    }
}

bool PlayChess::empty(int player, int number, const std::vector<std::vector<int>>& chess){
    return chess[player][number] == 0;
}

bool PlayChess::emptyAll(int player, const std::vector<std::vector<int>>& chess){
    for (int i = 0; i < 6; i ++) {
        if (!empty(player, i, chess)) {
            return false;
        }
    }
    return true;
}

