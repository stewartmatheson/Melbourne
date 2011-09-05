/*
 *  MenuState.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 13/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "MenuState.h"


MenuState::MenuState(sf::RenderWindow* a, std::string const &t) : State(a), currently_selected_index(0), title(t) {}

void MenuState::handle_step()
{
    for(int i = 0; i < items.size(); i++)
        items[i].draw();
}

void MenuState::handle_event(sf::Event* e)
{
    if (app->GetInput().IsKeyDown(sf::Key::Up))
        move_selection_up();
    
    if (app->GetInput().IsKeyDown(sf::Key::Down))
        move_selection_down();

    if (app->GetInput().IsKeyDown(sf::Key::Return))
        items[currently_selected_index].call_action();
}

void MenuState::move_selection_up()
{
    if(currently_selected_index > 0 && currently_selected_index < items.size())
    {
        currently_selected_index--;
        update_selection();
    }
}

void MenuState::move_selection_down()
{
    if(currently_selected_index < items.size() - 1)
    {
        currently_selected_index++;
        update_selection();
    }
}

void MenuState::update_selection()
{
    for(int i = 0; i < items.size(); i++)
        items[i].set_selected(false);
    items[currently_selected_index].set_selected(true);
}