/*
 *  ExplosionView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 16/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class animates the simple explosion that occurs when the eneimes are killed.
 *  It makes an SFML circle class grow and change colors from yellow to red using a timer.
 */


#ifndef EXPLOSION_VIEW_H
#define EXPLOSION_VIEW_H

#include <SFML/Graphics.hpp>
#include "View.h"
#include "Subject.h"

class ExplosionView : public View
{
    sf::Shape circle;
    sf::Clock timer;
    int max_radius, radius_per_second;
    bool start_animation;
public:
    ExplosionView(sf::RenderWindow* a);
    virtual void const draw();
    virtual void notify(Subject* s);
    void start();
};

#endif