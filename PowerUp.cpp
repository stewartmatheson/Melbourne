/*
 *  PowerUp.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "PowerUp.h"
#include "Player.h"

PowerUp::PowerUp(b2Body* b) : WorldModel(b) 
{
    power_up_state = new PowerUpState;
    power_up_state->set_firespeed_modifier(2.0f);
}

void PowerUp::collide(WorldModel* wm)
{
    if(wm->get_model_type() == PLAYER_MODEL)
    {
        Player* p;
        p = dynamic_cast<Player *>(wm);
        p->set_powerup_state(power_up_state);
        dispose();
    }
}

bool PowerUp::get_damage(){ return false; }
damage_types PowerUp::get_damage_type(){ return COLLIDE; }
model_type PowerUp::get_model_type(){ return POWER_UP; }