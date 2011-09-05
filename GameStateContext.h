/*
 *  GameStateContext.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This game is one huge state. This is the context class that manages the states. The class 
 *  handles dispaching to the currect state and handles creating the next state after the 
 *  current state is flagged as disposed. The state is updated after a level or after a menu.
 */

#ifndef GAME_STATE_CONTEXT_H 
#define GAME_STATE_CONTEXT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "State.h"


class GameStateContext
{
	State* state;
public:
	GameStateContext(sf::RenderWindow* a);
	void dispatch_step();
	void dispatch_events(sf::Event* e);
};

#endif