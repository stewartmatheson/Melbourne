/*
 *  DeathMenu.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 20/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "DeathMenu.h"
#include "ExitApplicationAction.h"
#include "NewGameAction.h"
#include "FirstLevel.h"
#include "MenuItem.h"

DeathMenu::DeathMenu(sf::RenderWindow* a, std::string const &t) : MenuState(a, t)
{
    int top_border = 0;
    int left_border = 0;
    int width = 300;
    int height = 35;
    int border = 5;
    
    MenuItem new_game = MenuItem(a, 
                                 "Retry", 
                                 left_border, 
                                 top_border, 
                                 height, 
                                 width , 
                                 true
                                 );
    NewGameAction* new_game_menu_action = new NewGameAction(a, this);
    new_game.set_action(new_game_menu_action);
    items.push_back(new_game);
    
    MenuItem exit = MenuItem(a, 
                             "Exit", 
                             left_border, 
                             top_border + ((height + border) * 1), 
                             height, 
                             width
                             );
    
    MenuItemAction* exit_action = new ExitApplicationAction(a);
    exit.set_action(exit_action);
    
    items.push_back(exit);
    update_selection();
}

State* DeathMenu::get_next_state() 
{ 
    FirstLevel* f = new FirstLevel(app);
    return f; 
}