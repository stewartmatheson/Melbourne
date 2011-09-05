/*
 *  Enemy.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 12/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Enemy.h"


void Enemy::step()
{
    //body->ApplyForce(b2Vec2(.0f, .0f), b2Vec2(.0f, .0f));
    b2Vec2 f = b2Vec2(target->get_x_position(), target->get_y_position());
    b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0f, 0.0f));
    body->ApplyForce(f, p);
    notify_observers();
}

void Enemy::collide(WorldModel* wm)
{
    if(wm->get_damage() && wm->get_damage_type() == BULLET)
        start_disposing();
    
    if(wm->get_model_type() == PLAYER_MODEL)
        start_disposing();
}

void Enemy::start_disposing()
{
    die_sound->play();
    ex_view->start();
}

bool Enemy::get_damage() { return true; }
damage_types Enemy::get_damage_type() { return COLLIDE; }
model_type Enemy::get_model_type(){ return ENEMY_MODEL; }
void Enemy::set_explosion_view(ExplosionView* e) { ex_view = e; }
void Enemy::set_target(WorldModel* t)
{     
    target = t;
    /*
    b2MouseJointDef md;
    md.body1 = body;
    md.body2 = target->get_body();
    md.target = body->GetWorldCenter();
    md.maxForce = (body->GetMass() < 16.0)? 
    (1000.0f * body->GetMass()) : float32(16000.0);
    md.maxForce = 1000.0f * body->GetMass();
    follow_joint = (b2MouseJoint*)body->GetWorld()->CreateJoint(&md);
    */
}

void Enemy::set_die_sound(Sound* s) { die_sound = s; } 