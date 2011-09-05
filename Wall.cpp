/*
 *  Wall .cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Wall.h"

void Wall::step(){}
void Wall::collide(WorldModel* wm){}
bool Wall::get_damage(){ return false; }
damage_types Wall::get_damage_type(){ return COLLIDE; }
model_type Wall::get_model_type(){ return WALL_MODEL; }