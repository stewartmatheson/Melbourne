/*
 *  Wall.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class handles the walls around the game area. The walls stop the player
 *  from being able to fly off the screen.
 */

#ifndef WALL_H
#define WALL_H

#include "WorldModel.h"

class Wall : public WorldModel
{
public:
    Wall(b2Body* b) : WorldModel(b) {};
    virtual void step();
    virtual void collide(WorldModel* wm);
    virtual bool get_damage();
    virtual damage_types get_damage_type();
    virtual model_type get_model_type();
};

#endif WALL_H