/*
 *  PowerUpView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 19/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  Blue circle with a red P. What you would expect a powerup to look like.
 */

#ifndef POWER_UP_VIEW_H
#define POWER_UP_VIEW_H

#include <SFML/Graphics.hpp>
#include "View.h"
#include "Subject.h"

class PowerUpView : public View
{
    sf::Shape background;
    sf::String text;
public:        
    PowerUpView(sf::RenderWindow* a);
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif