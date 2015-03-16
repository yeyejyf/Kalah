//
//  PlayChess.h
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#ifndef __Kalah__PlayChess__
#define __Kalah__PlayChess__

#include <vector>

class PlayChess{
    
    static int sowOpposite(int player, int count, std::vector<std::vector<int>>& chess);
    static void captureOpposite(int player, int current, std::vector<std::vector<int>>& chess);
    
public:
    static int sowSeed(int player, int number, std::vector<std::vector<int>>& chess, int win);
    static bool empty(int player, int number, const std::vector<std::vector<int>>& chess);
    static bool emptyAll(int player, const std::vector<std::vector<int>>& chess);
    
};

#endif /* defined(__Kalah__PlayChess__) */
