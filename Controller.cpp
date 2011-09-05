/*
 *  Controller.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 7/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Controller.h"
#include "Bullet.h"
#include <iostream>

void const Controller::incoming_event(sf::Event* e, sf::RenderWindow* a)
{
    if ((e->Type == sf::Event::KeyPressed) && (e->Key.Code == sf::Key::Right))
        right_key_down = true;
    if ((e->Type == sf::Event::KeyReleased) && (e->Key.Code == sf::Key::Right))
        right_key_down = false;
    if ((e->Type == sf::Event::KeyPressed) && (e->Key.Code == sf::Key::Left))
        left_key_down = true;
    if ((e->Type == sf::Event::KeyReleased) && (e->Key.Code == sf::Key::Left))
        left_key_down = false;
    if ((e->Type == sf::Event::KeyPressed) && (e->Key.Code == sf::Key::Up))
        up_key_down = true;
    if ((e->Type == sf::Event::KeyReleased) && (e->Key.Code == sf::Key::Up))
        up_key_down = false;
    if ((e->Type == sf::Event::KeyPressed) && (e->Key.Code == sf::Key::Down))
        down_key_down = true;
    if ((e->Type == sf::Event::KeyReleased) && (e->Key.Code == sf::Key::Down))
        down_key_down = false;
    if ((e->Type == sf::Event::KeyPressed) && (e->Key.Code == sf::Key::LControl))
        lcontrol_key_down = true;
    if ((e->Type == sf::Event::KeyReleased) && (e->Key.Code == sf::Key::LControl))
        lcontrol_key_down = false;
}

void Controller::step()
{
    if(up_key_down)
    {
        b2Vec2 f = player->get_body()->GetWorldVector(b2Vec2(0.0f, -70.0f));
        b2Vec2 p = player->get_body()->GetWorldPoint(b2Vec2(0.0f, 0.0f));
        player->get_body()->ApplyForce(f, p);
    }
    
    if(down_key_down)
    {
        b2Vec2 f = player->get_body()->GetWorldVector(b2Vec2(0.0f, 70.0f));
        b2Vec2 p = player->get_body()->GetWorldPoint(b2Vec2(0.0f, 0.0f));
        player->get_body()->ApplyForce(f, p);     
    }
    
    if(left_key_down)
        player->get_body()->SetAngularVelocity(-3.00f);
    
    if(right_key_down)
        player->get_body()->SetAngularVelocity(3.00f);
    
    if (lcontrol_key_down)
    {
        int energy_cost = 2;
        int fire_speed = player->get_fire_speed();
        if(fire_speed < fire_timer.GetElapsedTime() && player->get_energy() > energy_cost)
        {
            fire.play();
            Bullet* b = game_factory->create_bullet(player);
            state_models->push_back(b);
            player->reduce_energy(energy_cost);
            fire_timer.Reset();
            
        }
    }
    
}