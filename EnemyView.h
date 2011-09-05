/*
 *  EnemyView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 12/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The sprite for the enemy ships.
 */

#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <SFML/Graphics.hpp>
#include "SpriteView.h"

class EnemyView : public SpriteView
{
public:
    EnemyView(sf::RenderWindow* a);
};

#endif