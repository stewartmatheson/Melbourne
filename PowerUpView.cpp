/*
 *  PowerUpView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 19/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "PowerUpView.h"
#include "WorldModel.h"

PowerUpView::PowerUpView(sf::RenderWindow* a) : View(a) {}
void const PowerUpView::draw(){}
void PowerUpView::notify(Subject* s)
{
    WorldModel* m;
    m = dynamic_cast<WorldModel *>(s);
    background = sf::Shape::Circle(m->get_x_position(), m->get_y_position(), 13, sf::Color(100, 100, 255));
    app->Draw(background);
    text.SetText("P");
    text.SetSize(22); 
    text.SetColor(sf::Color(255,0,0));
    text.SetPosition(m->get_x_position() - 6, m->get_y_position() - 13);
    app->Draw(text);
}