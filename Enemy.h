/*
 *  Enemy.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 12/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class holds all the enemy actions and how the enemies work. It also 
 *  moves the enemies and makes them follow the player. It also controls the collisions
 *  and kills the enemies if they hit a bullet.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "WorldModel.h"
#include "Box2D.h"
#include "ExplosionView.h"
#include "Player.h"
#include "Sound.h"

class Enemy : public WorldModel
{
    void start_disposing();
    ExplosionView* ex_view;
    WorldModel* target;
    b2MouseJoint* follow_joint;
    Sound* die_sound;
public:
    Enemy(b2Body* b) : WorldModel(b) {};
    virtual void step();
    virtual void collide(WorldModel* wm);
    virtual bool get_damage();
    virtual damage_types get_damage_type();
    void set_explosion_view(ExplosionView* e);
    void set_target(WorldModel* t);
    virtual model_type get_model_type();
    void set_die_sound(Sound*  s);
};

#endif