/*
 *  World.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "World.h"

void World::step()
{ 
    notify_observers();
}