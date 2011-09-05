/*
 *  StarField.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  Random rendering of a starfield.
 */

#ifndef STARFIELD_H
#define STARFIELD_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "View.h"
#include "Subject.h"

class StarFieldView : public View
{
    std::vector<sf::Shape> field;
    sf::Shape create_random_star();
public:        
    StarFieldView(sf::RenderWindow* a);
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif