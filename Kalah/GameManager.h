//
//  GameManager.h
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#ifndef __Kalah__GameManager__
#define __Kalah__GameManager__

#include <vector>

class GameManager{
    
    std::vector<std::vector<int>> _chess;
    int _win;
    const int _seed;
    
public:
    GameManager(int seed = 3);
    int sowSeed(int player, int number);
    void printTable(int player) const;
    bool checkWin(int player);
    bool empty(int player, int number);
    bool emptyAll(int player);
    int clear(int player);
    int nSeeds(int player, int number);
    int getSeedCount() const;
    
    std::vector<std::vector<int>> getChess() const;
    
    // Only for the use of test
    void fakeChess(int[2][7]);
    
};

#endif /* defined(__Kalah__GameManager__) */
