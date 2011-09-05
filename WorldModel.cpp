/*
 *  WorldModel.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "WorldModel.h"

b2Body* const WorldModel::get_body(){ return body; } 

float const WorldModel::get_angle(){ return body->GetAngle(); }

float const WorldModel::get_x_position(){ return body->GetPosition().x; }

float const WorldModel::get_y_position(){ return body->GetPosition().y; }

void WorldModel::step()
{ 
    notify_observers();
}

WorldModel::~WorldModel()
{
    detatch_observers();
    body->SetUserData(false);
    b2World* w = body->GetWorld();
    w->DestroyBody(body);
} 