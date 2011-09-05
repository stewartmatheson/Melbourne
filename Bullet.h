/*
 *  Bullet.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 9/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  Each time  a player fires their gun a bullet is created from this class.
 *  this class handles the collisions of these bullets and also holds a pointer
 *  to the player that fired the bullet.
 */

#ifndef BULLET_H
#define BULLET_H

#include "WorldModel.h"
#include "Player.h"

class Bullet : public WorldModel
{
    Player* player;
public:
    Bullet(b2Body* b, Player* p) : player(p), WorldModel(b) {};
    virtual void collide(WorldModel* wm);
    virtual bool get_damage();
    virtual damage_types get_damage_type();
    virtual model_type get_model_type();
};

#endif