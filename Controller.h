/*
 *  Controller.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 7/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The controller class maps all of the players actions to the models that are in the game.
 *  The controller class handles things like creating bullets moving the ship and also handles
 *  the key up key down toggle values VIA sfml events.
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameFactory.h"
#include "Model.h"
#include "Sound.h"

class Controller
{
    Player* player;
    GameFactory* game_factory;
    std::vector<Model* >* state_models;
    bool up_key_down, down_key_down, left_key_down, right_key_down, lcontrol_key_down;
    Sound fire;
    sf::Clock fire_timer;
public:
    Controller(Player* p, GameFactory* g, std::vector<Model* >* m) : player(p), game_factory(g), state_models(m), up_key_down(false), down_key_down(false), left_key_down(false), right_key_down(false), lcontrol_key_down(false), fire("fire.ogg", 1.00f, 10.0f) {};
    void const incoming_event(sf::Event* e, sf::RenderWindow* a);
    void step();
};

#endif