/*
 *  BulletView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 9/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The view for the bullet. Just a circle... simple stuff.
 */

#ifndef BULLET_VIEW_H
#define BULLET_VIEW_H

#include <SFML/Graphics.hpp>
#include "View.h"
#include "Subject.h"

class BulletView : public View
{
    sf::Shape circle;
public:
    BulletView(sf::RenderWindow* a);
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif