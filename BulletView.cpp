/*
 *  BulletView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 9/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "BulletView.h"
#include "WorldModel.h"
#include <iostream>

BulletView::BulletView(sf::RenderWindow* a) : View(a)
{
    
}

void const BulletView::draw()
{
}

void BulletView::notify(Subject* s)
{
    WorldModel* m;
    m = dynamic_cast<WorldModel *>(s);
    //circle.Move(m->get_x_position(), m->get_y_position());
    circle = sf::Shape::Circle(m->get_x_position(), m->get_y_position(), 4, sf::Color(10, 255, 1, 255));
    app->Draw(circle);
    draw();
}