/*
 *  EnergyView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 19/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The view that prints the energy score out. This is updated by the player class.∂
 */

#ifndef ENERGY_VIEW_H
#define ENERGY_VIEW_H

#include "View.h"
#include "Subject.h"

class EnergyView : public View
{
    sf::String text;
public:
    EnergyView(sf::RenderWindow* a) : View(a) {};
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif