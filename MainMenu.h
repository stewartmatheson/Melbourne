/*
 *  MainMenu.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 * 
 *  The main menu state at the start of the game to get the first level underway.
 *  
 */

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include <string>

class MainMenu : public MenuState
{
public:
    MainMenu(sf::RenderWindow* a, std::string const &t);
    virtual State* get_next_state();
};

#endif