/*
 *  PowerUpState.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class handles the power up state that the player model uses to put the change
 *  on the player when they get a powerup.
 */

#ifndef POWER_UP_STATE_H
#define POWER_UP_STATE_H

class PowerUpState
{
    float firespeed_modifier;
public:
    PowerUpState() : firespeed_modifier(0) {};
    float const get_firespeed_modifier();
    void set_firespeed_modifier(float const f);
};

#endif