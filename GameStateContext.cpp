/*
 *  GameStateContext.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "GameStateContext.h"
#include "FirstLevel.h"
#include "MainMenu.h"

GameStateContext::GameStateContext(sf::RenderWindow* a)
{
    state = new MainMenu(a, "Space Frenzy");
}

void GameStateContext::dispatch_events(sf::Event* e)
{
    state->handle_event(e);
}

void GameStateContext::dispatch_step()
{
	if(state->is_next_state())
    {
        State* s = state->get_next_state();
        delete state;
        state = s;
    }
    state->handle_step();
}