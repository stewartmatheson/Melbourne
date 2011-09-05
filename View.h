/*
 *  View.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the base view class. All other views are inheretted from this class. This 
 *  class extends the observer class that is used in the subject observer pattern
 *  that all views in this project use.
 */

#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "Subject.h"

class View : public Observer
{
    bool disposed;
protected:
    sf::RenderWindow* app;
public:
    View(sf::RenderWindow* a);
	virtual void const draw() = 0;
    virtual void notify(Subject* s) = 0;
    bool is_disposed();
    void dispose();
};

#endif