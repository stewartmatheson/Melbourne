/*
 *  Player.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Player.h"
#include <iostream>

void Player::collide(WorldModel* wm)
{
    if(wm->get_model_type() == ENEMY_MODEL)
        reduce_energy(10);
}


bool Player::get_damage() { return false; }
damage_types Player::get_damage_type() { return COLLIDE; }
model_type Player::get_model_type() { return PLAYER_MODEL; }
int Player::get_score(){ return score; }
int Player::get_energy(){ return energy; }
void Player::add_score(int s)
{ 
    score = score + s;
    if(score > high_score_manager.get())
        high_score_manager.set(score);
}

void Player::set_powerup_state(PowerUpState* p) 
{ 
    power_up_state = p;
    power_up = true;
}

int Player::get_fire_speed()
{
    if(power_up)
        return fire_speed / power_up_state->get_firespeed_modifier();
    else
        return fire_speed;
}

void Player::step()
{
    if(energy < 0)
        kill();
        
    if(energy < 100 && energy_timer.GetElapsedTime() > charge_rate)
    {
        energy++;
        energy_timer.Reset();
    }
    notify_observers();
}

void Player::reduce_energy(int e){ energy = energy - e; }
void Player::kill(){ dead = true; }
bool Player::is_dead() { return dead; }
int Player::get_high_score(){ return high_score_manager.get(); }
