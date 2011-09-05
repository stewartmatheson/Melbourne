/*
 *  MenuState.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 13/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the state that is used by the in game menus. It handles all the controls 
 *  for the menu and also handles the menu items and their actions.
 */

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "MenuItem.h"
#include <vector>
#include <string>

class MenuState : public State
{
    void move_selection_up();
    void move_selection_down();
    std::string title;
protected:
    std::vector<MenuItem> items;
    int currently_selected_index;
    void update_selection();
public:
    MenuState(sf::RenderWindow* a, std::string const &t);
    virtual void handle_event(sf::Event* e);
    virtual void handle_step();
};

#endif