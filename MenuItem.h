/*
 *  MenuItem.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class is used by the menu state and renders the menu item as well as managing
 *  the current action. This current action is a class that holds the action of the menu.
 */

#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "View.h"
#include "Subject.h"
#include "MenuItemAction.h"

class MenuItem : public View
{
    std::string item_text;
    MenuItemAction* current_action;
    sf::Font menu_font;
    bool is_selected;
    int xpos, ypos, height, width;
public:
    MenuItem(sf::RenderWindow* a, std::string const &t, int const x, int const y, int const h, int const w, bool selected = false);
    virtual void const draw();
    virtual void notify(Subject* s);
    void set_selected(bool s);
    void call_action();
    void set_action(MenuItemAction* a);
};

#endif 