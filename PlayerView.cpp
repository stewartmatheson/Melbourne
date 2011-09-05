/*
 *  PlayerView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "PlayerView.h"
#include "WorldModel.h"
#include <iostream>

PlayerView::PlayerView(sf::RenderWindow* a) : SpriteView(a)
{
    std::string file_name = "leytonstoneshippmask.png"; 
	init_sprite(file_name);
    a->SetView(game_view);
}

void PlayerView::notify(Subject* s)
{
    WorldModel* m;
    m = dynamic_cast<WorldModel *>(s);
    sprite.SetPosition(m->get_x_position(), m->get_y_position());
	sprite.SetRotation((m->get_angle() * (180 / 3.14f)) * -1);
    game_view.SetHalfSize(app->GetWidth() / 2, app->GetHeight() / 2);
    game_view.SetCenter(m->get_x_position(), m->get_y_position());
    draw();
}