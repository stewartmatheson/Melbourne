/*
 *  MenuItem.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "MenuItem.h"

MenuItem::MenuItem(sf::RenderWindow* a, std::string const &t, int x, int y, int h, int w, bool selected) : View(a), item_text(t), xpos(x), ypos(y), height(h), width(w), is_selected(selected)
{
    menu_font.LoadFromFile("font.ttf", 50);
}

void const MenuItem::draw()
{
    sf::Color text_color;
    sf::Shape rect;
    if(is_selected)
    {
        text_color = sf::Color::White;
        rect = sf::Shape::Rectangle(xpos, ypos,  xpos + width, ypos + height, sf::Color::Black, 5, sf::Color::White);
    }
    else
    {
        text_color = sf::Color::Black;
        rect = sf::Shape::Rectangle(xpos, ypos,  xpos + width, ypos + height, sf::Color::White);
    }
    
    sf::String text;
    text.SetText(item_text);
    text.SetSize(24);
    text.Move(xpos + 15, ypos + 3);
    text.SetColor(text_color);

    app->Draw(rect);
    app->Draw(text);
}

void MenuItem::set_selected(bool s) { is_selected = s; }
void MenuItem::notify(Subject* s){}
void MenuItem::call_action(){ current_action->action(); }
void MenuItem::set_action(MenuItemAction* a){ current_action = a; }