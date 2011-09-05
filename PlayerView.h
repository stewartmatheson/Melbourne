/*
 *  PlayerView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The sprite for the main ship.
 */

#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include <SFML/Graphics.hpp>
#include "SpriteView.h"

class PlayerView : public SpriteView
{
    sf::View game_view;
public:
    PlayerView(sf::RenderWindow* a);
    virtual void PlayerView::notify(Subject* s);
};

#endif