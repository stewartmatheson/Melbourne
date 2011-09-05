/*
 *  Bullet.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 9/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#ifndef BULLET_H
#define BULLET_H

#include "WorldModel.h"
#include "Player.h"

class Bullet : public WorldModel
{
public:
    Bullet(b2Body* b, Player* p) : WorldModel(b) {}
};

#endif