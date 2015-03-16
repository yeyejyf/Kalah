//
//  Player.h
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#ifndef __Kalah__Player__
#define __Kalah__Player__

#include "GameManager.h"
#include "RunnablePlayer.h"
#include <string>

class Player: public RunnablePlayer{
    
    int _id;
    GameManager *mgr;
    std::string _name;
    
    void clear();
    
public:
    
    Player(int player, GameManager& gm, const std::string& name);
    bool run();
};


#endif /* defined(__Kalah__Player__) */
