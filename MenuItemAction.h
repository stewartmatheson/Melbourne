/*
 *  MenuItemAction.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  Each menu item has an action. This action is invoced when the menu item is selected. 
 */

#ifndef MENU_ITEM_ACTION_H
#define MENU_ITEM_ACTION_H

#include <SFML/Graphics.hpp>

class MenuItemAction
{
protected:
    sf::RenderWindow* app;
public:
    MenuItemAction(sf::RenderWindow* a) : app(a) {}
    virtual void action() = 0;
};

#endif