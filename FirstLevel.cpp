/*
 *  FirstLevel.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "FirstLevel.h"
#include "GameFactory.h"
#include "Enemy.h"
#include "MusicTrack.h"
#include "World.h"
#include "DeathMenu.h"

FirstLevel::FirstLevel(sf::RenderWindow* a) : GameState(a), enemy_time_delay(10.00f)
{
    //create the factory
    factory = new GameFactory(a);
    world = factory->get_world();
    
    //create walls
    //Wall* left_wall = factory->create_wall(0, 0, 10, 150);
    //add_model(left_wall);
        
    //create the main player
    current_player = factory->create_player();
    add_model(current_player);
    
    //create the controller
    player_controller = new Controller(current_player, factory, &models);
    
    //add the music
    MusicTrack* music_track = factory->create_music_track();
    add_model(music_track);
    
    //create the world
    World* w = factory->create_world();
    add_model(w);
    
    //now add a powerup
    PowerUp* pu = factory->create_powerup();
    add_model(pu);
}

State* FirstLevel::get_next_state()
{
    DeathMenu* d = new DeathMenu(app, "You are Dead!");
    return d;
}

void FirstLevel::handle_step()
{
    if(current_player->is_dead())
        finished();
    
    if(enemy_time_delay < new_enemy_timer.GetElapsedTime())
    {
        Enemy* enemy;
        enemy = factory->create_enemy();
        enemy->set_target(current_player);
        add_model(enemy);
        new_enemy_timer.Reset();
        if(enemy_time_delay > 1.00f)
            enemy_time_delay = enemy_time_delay - 1.00f;
        
    }
    GameState::handle_step();
}