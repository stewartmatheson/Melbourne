/*
 *  WorldModel.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *  
 *  This is the main world class. It contains the box2d body and provicds methods
 *  for the views to get information about the current body in the world.
 *  When ever somehting new needs to get added to the world this class is used.
 */

#ifndef WORLD_MODEL_H
#define WORLD_MODEL_H

#include "Model.h"
#include "Box2D.h"

enum damage_types { COLLIDE, BULLET };
enum model_type { PLAYER_MODEL, BULLET_MODEL, ENEMY_MODEL, WALL_MODEL, POWER_UP};


class WorldModel : public Model
{
protected:
    b2Body* body;
public:
    WorldModel(b2Body* b) : body(b), Model() {};
    ~WorldModel();
    float const get_angle();
    float const get_x_position();
    float const get_y_position();
    b2Body* const get_body();
    virtual void step();
    virtual void collide(WorldModel* wm) = 0;
    virtual bool get_damage() = 0;
    virtual damage_types get_damage_type() = 0;
    virtual model_type get_model_type() = 0;
};

#endif