/*
 *  HighScoreManager.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 20/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#ifndef HIGH_SCORE_MANAGER_H
#define HIGH_SCORE_MANAGER_H

#include <iostream>
#include <fstream> 

class HighScoreManager
{
    std::ofstream out;
    std::ifstream in;
    int score;
public:
    HighScoreManager();
    int get();
    void set(int s);
};

#endif