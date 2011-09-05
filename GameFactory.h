/*
 *  GameFactory.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the class that creates all the ojbects needed by the levels in the game. 
 *  All new game objects are created with in this factory. There are a number of 
 *  models that need to be created with a box2d body and some models that have more than
 *  one view.
 */

#ifndef GAME_FACTORY_H 
#define GAME_FACTORY_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Box2D.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MusicTrack.h"
#include "World.h"
#include "Wall.h"
#include "PowerUp.h"
#include "Sound.h"

class GameFactory
{
    b2World* world;
    sf::RenderWindow* app;
    Sound die_sound;
public:
    b2World* get_world();
    GameFactory(sf::RenderWindow* a);
	Player* create_player();
    Bullet* create_bullet(Player* p);
    Enemy* create_enemy();
    b2Body* create_box2d_body(float const x, float const y, float const xpos, float const ypos, bool is_static = false);
    MusicTrack* create_music_track();
    World* create_world();
    Wall* create_wall(int const x_pos, int const y_pos, int const length, int const wall_thickness);
    PowerUp* create_powerup();
};

#endif