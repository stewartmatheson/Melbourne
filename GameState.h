/*
 *  GameState.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the main game state class. This is what is loaded in to the game
 *  state context when the game is loaded and playing a level. This class has
 *  the player the player controller and also the physics world.
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Model.h"
#include "Controller.h"
#include "State.h"

class GameState : public State
{
protected:
	std::vector<Model*> models;
    Controller* player_controller;
    b2World* world;
    sf::Clock clock;
public:
    GameState(sf::RenderWindow* a);
	~GameState();
    void handle_event(sf::Event* e);
	virtual void handle_step();
    void add_model(Model* m);
};

#endif