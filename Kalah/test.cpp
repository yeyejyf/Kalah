//
//  test.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "GameManager.h"
#include "Player.h"
#include "AI.h"
#include "Gamer.h"

void test1(){
    
    
    GameManager gm(3);
    
    int p[2][7]={
        {6, 5, 4, 3, 2, 1, 0},
        {3, 3, 3, 3, 3, 3, 0}
    };
    gm.fakeChess(p);
    Player player(1, gm, "Yunfan Jin");
    AI ai(0,gm, "Foolish AI");
    ai.run();
}
