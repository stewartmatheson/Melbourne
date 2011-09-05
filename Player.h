/*
 *  Player.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The player model is the current player of the game. Score energy and power ups are 
 *  all stored in this class.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "WorldModel.h"
#include "Box2D.h"
#include "PowerUpState.h"
#include "HighScoreManager.h"

class Player : public WorldModel
{
    int score;
    float fire_speed, energy;
    PowerUpState* power_up_state;
    bool power_up, dead;
    sf::Clock energy_timer;
    int charge_rate;
    HighScoreManager high_score_manager;
public:
    Player(b2Body* b) : WorldModel(b), score(0), power_up(false), dead(false), fire_speed(1.0f), energy(50), charge_rate(.90f) {};
    virtual void collide(WorldModel* wm);
    virtual bool get_damage();
    virtual damage_types get_damage_type();
    int get_score();
    void add_score(int s);
    virtual model_type get_model_type();
    void set_powerup_state(PowerUpState* p);
    int get_fire_speed();
    int get_energy();
    void step();
    void reduce_energy(int e);
    void kill();
    bool is_dead();
    int get_high_score();
};

#endif