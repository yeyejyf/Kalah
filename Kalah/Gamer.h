//
//  Gamer.h
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#ifndef __Kalah__Gamer__
#define __Kalah__Gamer__

#include <string>

class Gamer{
    
public:
    void play(int level = 6, int seed = 3, std::string name = "Player");
    void start();
    
};

#endif /* defined(__Kalah__Gamer__) */
