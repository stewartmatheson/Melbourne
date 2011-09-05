/*
 *  MainMenu.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "MainMenu.h"
#include "ExitApplicationAction.h"
#include "NewGameAction.h"
#include "FirstLevel.h"

MainMenu::MainMenu(sf::RenderWindow* a, std::string const &t) : MenuState(a, t)
{
    int top_border = 200;
    int left_border = 200;
    int width = 300;
    int height = 35;
    int border = 5;
    
    MenuItem new_game = MenuItem(a, 
                                "New Game", 
                                 left_border, 
                                 top_border, 
                                 height, 
                                 width , 
                                 true
                                );
    NewGameAction* new_game_menu_action = new NewGameAction(a, this);
    new_game.set_action(new_game_menu_action);
    items.push_back(new_game);

    MenuItem oo = MenuItem(a, 
                           "Other Option",
                           left_border, 
                           top_border + ((height + border) * 1), 
                           height, 
                           width
                           );
    items.push_back(oo);    
    
    MenuItem yoo = MenuItem(a, 
                            "Yet another option", 
                            left_border, 
                            top_border + ((height + border) * 2), 
                            height, 
                            width
                            );
    items.push_back(yoo);
    
    MenuItem exit = MenuItem(a, 
                             "Exit", 
                             left_border, 
                             top_border + ((height + border) * 3), 
                             height, 
                             width
                            );
    
    MenuItemAction* exit_action = new ExitApplicationAction(a);
    exit.set_action(exit_action);
    
    items.push_back(exit);
    update_selection();
}

State* MainMenu::get_next_state() 
{ 
    FirstLevel* f = new FirstLevel(app);
    return f; 
}

