/*
 *  HighScoreManager.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 20/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "HighScoreManager.h"

HighScoreManager::HighScoreManager() : out("score.txt"), in("score.txt"), score(0)
{
    if(!out)
        std::cout << "Cant read file!";
    
    out << 1000;
    
    if(!in)
        std::cout << "Cant read file!";
    
    in >> score;
    in.close();
}

void HighScoreManager::set(int s) { score = s; } 
int HighScoreManager::get(){ return score; }