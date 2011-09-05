/*
 *  World.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The world class is a simle model that handles all constant views. In this case
 *  it holds the star field rendering.
 */

#ifndef WORLD_H
#define WORLD_H

#include "Model.h"

class World : public Model
{
public:
    virtual void step();
};

#endif