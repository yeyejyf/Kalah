//
//  HardAI.h
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#ifndef __Kalah__HardAI__
#define __Kalah__HardAI__

#include "AI.h"
#include <utility>

class HardAI: public AI{
    
    int _level;
    
    std::vector<int> getScore(const std::vector<std::vector<int>>& chess);
    std::vector<int> recursion(int player, const std::vector<std::vector<int>>& chess, int level, int win);
    
protected:
    virtual int chooseHouse();
    
public:
    HardAI(int player, GameManager& gm, std::string name);
    void setHard(int level);
    
};

#endif /* defined(__Kalah__HardAI__) */
