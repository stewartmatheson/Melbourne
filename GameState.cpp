/*
 *  GameState.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "GameState.h"
#include <iostream>

GameState::GameState(sf::RenderWindow* a) : State(a)
{
    //clock.Reset();
}

GameState::~GameState()
{
    for(int i = 0; i < models.size(); i++)
        delete models[i];
}

void GameState::handle_event(sf::Event* e)
{
    player_controller->incoming_event(e, app);
}

void GameState::handle_step()
{   
    player_controller->step();
	for(int i = 0; i < models.size(); i++)
    {
        if(models[i]->is_disposed())
        {
            delete models[i];
            models.erase(models.begin() + i);
        }
        else
            models[i]->step();
	}
    world->Step(1.0f / 30.0f, 10);
}

void GameState::add_model(Model* m)
{
    models.push_back(m);
}