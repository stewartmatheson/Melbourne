/*
 *  ExplosionView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 16/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "ExplosionView.h"
#include "WorldModel.h"
#include <iostream>

ExplosionView::ExplosionView(sf::RenderWindow* a) : View(a), max_radius(10), radius_per_second(5), start_animation(false)
{    
    timer.Reset();
}

void const ExplosionView::draw()
{

}

void ExplosionView::notify(Subject* s)
{
    WorldModel* m;
    m = dynamic_cast<WorldModel *>(s);    
    if(start_animation)
    {
        float current_radius = timer.GetElapsedTime() * radius_per_second;
        int circle_complete = (current_radius / max_radius) * 100;
        int blue_value = (circle_complete * 255) / 100;
        std::cout << circle_complete << '\n';
        std::cout << blue_value << '\n';
        circle = sf::Shape::Circle(m->get_x_position(), m->get_y_position(), current_radius, sf::Color(255, blue_value, 0));
        app->Draw(circle);
        draw();
        
        if(current_radius > max_radius)
            m->dispose();
        
    }
}

void ExplosionView::start() { start_animation = true; } 