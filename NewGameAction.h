/*
 *  NewGameAction.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This action creates a new game and is used in the menu state class.
 */

#ifndef NEW_GAME_ACTION_H
#define NEW_GAME_ACTION_H

#include <SFML/Graphics.hpp>
#include "MenuItemAction.h"
#include "MenuState.h"

class NewGameAction : public MenuItemAction
{
    MenuState* menu_state;
public:
    NewGameAction(sf::RenderWindow* a, MenuState* m) : MenuItemAction(a), menu_state(m) {}
    virtual void action();
};

#endif