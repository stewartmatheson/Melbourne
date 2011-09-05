/*
 *  State.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 13/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The state class is what the game uses in the game state context. The class is in extiance at 
 *  all times and handles all of the events that are dispached by the game context and the game
 *  facade.
 */

#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "Controller.h"

class State
{
protected:
    sf::RenderWindow* app;
    Controller* player_controller;
    bool next_state;
public:
    State(sf::RenderWindow* a) : app(a), next_state(false) {};
    virtual void handle_event(sf::Event* e) = 0;
    virtual void handle_step() = 0;
    bool is_next_state();
    virtual State* get_next_state() = 0;
    void finished();
};

#endif