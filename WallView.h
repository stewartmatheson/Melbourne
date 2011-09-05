/*
 *  WallView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  A simple box to show a wall view.
 */

#ifndef WALL_VIEW_H
#define WALL_VIEW_H

#include <SFML/Graphics.hpp>
#include "View.h"
#include "Subject.h"

class WallView : public View
{
    sf::Shape wall_shape;
public:        
    WallView(sf::RenderWindow* a);
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif