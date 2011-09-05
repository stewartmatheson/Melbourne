/*
 *  FirstLevel.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The game state for the first level. This is where everything is created and the factory is used.
 */

#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GameFactory.h"
#include "Player.h"

class FirstLevel : public GameState
{
    GameFactory* factory;
    sf::Clock new_enemy_timer;
    Player* current_player;
    float enemy_time_delay;
public:
    FirstLevel(sf::RenderWindow* a);
    virtual State* get_next_state();
    virtual void handle_step();
};

#endif