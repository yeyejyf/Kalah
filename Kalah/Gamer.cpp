//
//  Gamer.cpp
//  Kalah
//
//  Created by Yunfan Jin on 10/20/14.
//  Copyright (c) 2014 yunfan.jin. All rights reserved.
//

#include "Gamer.h"
#include "GameManager.h"
#include "Player.h"
#include "AI.h"
#include "HardAI.h"
#include <iostream>

void Gamer::start(){
    
    std::string name;
    std::cout << "Please kindly enter your name.\n";
    std::getline(std::cin, name);
    if (name == "") {
        name = "Player";
    }
    std::cout << "Hi, "<< name <<"!\n";
    std::cout << "Welcome to Kalah Game!\n";
    
    bool playable = true;
    
    while (playable) {
        int seed = 0;
        while (seed < 2 || seed > 10) {
            std::cout << "Please enter the number of seeds in each house.(2~10)\n";
            std::cin >> seed;
        }
        int level = -1;
        while (level < 0 || level > 10) {
            std::cout << "Please enter the difficulty level you want to try.(0~10)\n";
            std::cin >> level;
        }
        play(level, seed, name);
        char ans = 0;
        while (ans != 'y' && ans != 'n' &&
               ans != 'Y' && ans != 'N') {
            std::cout << "Wanna try again?(y/n)";
            std::cin  >> ans;
        }
        if (ans == 'n' || ans == 'N') {
            std::cout << "Thank you for playing the game.\n";
            playable = false;
        }
    }
}

void Gamer::play(int level, int seed, std::string name){
    GameManager gm(seed);
    std::cout << "Do you want to play the first?(y/n)";
    char ans;
    std::cin >> ans;
    while (ans != 'y' && ans != 'n' &&
           ans != 'Y' && ans != 'N') {
        std::cout << "Invald answer.\n";
        std::cin >> ans;
    }
    bool playfirst;
    if (ans == 'y' || ans == 'Y') {
        playfirst = true;
    }else{
        playfirst = false;
    }
    
    std::string ai_name;
    if (level < 2) {
        ai_name = "Easy AI";
    }else if (level < 4){
        ai_name = "Normal AI";
    }else if (level < 6){
        ai_name = "Hard AI";
    }else if (level < 8){
        ai_name = "Super Hard AI";
    }else{
        ai_name = "The GOD";
    }
    
    Player player(1, gm, name);
    HardAI ai(0, gm, ai_name);
    ai.setHard(level);
    
    if (playfirst) {
        bool tag = player.run();
        if (tag) {
            return;
        }
    }
    
    bool tag = false;
    while (!tag) {
        tag = ai.run();
        if (tag) {
            return;
        }
        tag = player.run();
    }
    
}