//
//  HardAI.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "HardAI.h"
#include "PlayChess.h"

int HardAI::chooseHouse(){
    
    int tag = -1;
    int max = 0;
    int win = mgr->getSeedCount() * 6;
    std::vector<std::vector<int>> chess = mgr->getChess();
    for (int i=0; i<6; i++) {
        if (PlayChess::empty(_id, i, chess)) {
            continue;
        }
        std::vector<std::vector<int>> new_chess = chess;
        int output = PlayChess::sowSeed(_id, i, new_chess, win);
        if (output == 10) {
            tag = i;
            break;
        }
        std::vector<int> result;
        if (output == 6) {
            result = recursion(_id, new_chess, _level, win);
        }else{
            result = recursion(1 - _id, new_chess, _level, win);
        }
        if (result[_id] > max) {
            max = result[_id];
            tag = i;
        }
    }
    
    return tag;
    
}

std::vector<int> HardAI::getScore(const std::vector<std::vector<int>>& chess){
    std::vector<int> v;
    for (int i=0; i<2; i++) {
        int sum = 0;
        for (int item: chess[i]) {
            sum += item;
        }
        //sum += chess[i][6] * 5;
        v.push_back(sum);
    }
    
    return v;
}

std::vector<int> HardAI::recursion(int player, const std::vector<std::vector<int>>& chess, int level, int win){
    if (level == 0 ) {
        return getScore(chess);
    }
    
    std::vector<int> max = {-1,-1};
    for (int i=0; i<6; i++) {
        if (PlayChess::empty(player, i, chess)) {
            continue;
        }
        std::vector<std::vector<int>> new_chess = chess;
        int output = PlayChess::sowSeed(player, i, new_chess, win);
        if (output == 10) {
            std::vector<int> result = {0, 0};
            result[player] = 2 * win;
            return result;
        }
        std::vector<int> result;
        if (output == 6) {
            result = recursion(player, new_chess, level - 1, win);
        }else{
            result = recursion(1 - player, new_chess, level - 1, win);
        }
        if (result[player] > max[player]) {
            max = result;
        }
    }
    
    if (max[0] > -1 && max[1] > -1) {
        return max;
    }
    
    max = getScore(chess);
    if (max[0] == max[1]) {
        return max;
    }
    if (max[1] > max[0]) {
        max[1] = win * 2;
        max[0] = 0;
    }else{
        max[0] = win * 2;
        max[1] = 0;
    }
    return max;
    
}

HardAI::HardAI(int player, GameManager& gm, std::string name):AI(player, gm, name){}

void HardAI::setHard(int level){
    _level = level;
}

