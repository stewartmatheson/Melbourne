/*
 *  EnemyView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 12/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "EnemyView.h"

EnemyView::EnemyView(sf::RenderWindow* a) : SpriteView(a)
{
    std::string file_name = "enemy.png"; 
	init_sprite(file_name);
}