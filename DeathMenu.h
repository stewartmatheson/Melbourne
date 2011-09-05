/*
 *  DeathMenu.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 20/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#ifndef DEATH_MENU_H
#define DEATH_MENU_H

#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include <string>

class DeathMenu : public MenuState
{
public:
    DeathMenu(sf::RenderWindow* a, std::string const &t);
    virtual State* get_next_state();
};

#endif