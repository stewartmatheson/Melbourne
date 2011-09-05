/*
 *  GameFacade.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "GameFacade.h"

GameFacade::GameFacade(sf::RenderWindow* a)
{
    context = new GameStateContext(a);
}

void GameFacade::process_event(sf::Event* e)
{
	context->dispatch_events(e);
}

void GameFacade::step()
{
    context->dispatch_step();
}