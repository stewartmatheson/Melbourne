/*
 *  Bullet.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 9/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Bullet.h"

void Bullet::collide(WorldModel* wm)
{
    if(wm->get_damage())
        dispose();
    
    if(wm->get_model_type() == ENEMY_MODEL)
        player->add_score(10);
}

bool Bullet::get_damage() { return true; } 
damage_types Bullet::get_damage_type() { return BULLET; }
model_type Bullet::get_model_type(){ return BULLET_MODEL; }