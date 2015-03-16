//
//  AI.h
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#ifndef __Kalah__AI__
#define __Kalah__AI__

#include "GameManager.h"
#include "RunnablePlayer.h"
#include <vector>
#include <string>

class AI: public RunnablePlayer{
    
    
    int oneMoreChance();
    std::vector<int> findAvailable();
    
    
protected:
    
    int _id;
    GameManager *mgr;
    std::string _name;
    
    void clear();
    virtual int chooseHouse();
    
public:
    
    AI(int player, GameManager& gm, std::string name);
    bool run();
};

#endif /* defined(__Kalah__AI__) */
