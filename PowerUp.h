/*
 *  PowerUp.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class holds the power ups and displays them before they are picked up. This 
 *  also returns the correct powerup state to the player when it is picked up.
 */

#ifndef POWER_UP_H
#define POWER_UP_H

#include "WorldModel.h"
#include "PowerUpState.h"

class PowerUp : public WorldModel
{
    PowerUpState* power_up_state;
public:
    PowerUp(b2Body* b);
    virtual void collide(WorldModel* wm);
    virtual bool get_damage();
    virtual damage_types get_damage_type();
    virtual model_type get_model_type();
};

#endif