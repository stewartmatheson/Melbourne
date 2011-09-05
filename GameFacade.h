/*
 *  GameFacade.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This facade class is the first class that gets created by the main game. 
 *  It provides a facade to the rest of the game so as not to clutter the main 
 *  game loop.
 */

#ifndef GAME_FACADE_H
#define GAME_FACADE_H

#include <SFML/Graphics.hpp>
#include "GameStateContext.h"

class GameFacade
{
	GameStateContext* context;
public:
	GameFacade(sf::RenderWindow* a);
	void process_event(sf::Event* e);
	void step();
};

#endif