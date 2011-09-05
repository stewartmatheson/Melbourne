/*
 *  SpriteView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include <typeinfo>
#include "SpriteView.h"
#include "WorldModel.h"

#include <iostream>

SpriteView::SpriteView(sf::RenderWindow* a) : View(a) {}

void SpriteView::init_sprite(std::string const &file_name)
{
	image.LoadFromFile(file_name);
	image.CreateMaskFromColor(sf::Color(0, 0, 0), 0);
	sprite.SetImage(image);
	float Width  = sprite.GetSize().x;
	float Height = sprite.GetSize().y;
	sprite.Resize(Width, Height);
	sprite.SetCenter(Width / 2, Height / 2);
}

void const SpriteView::draw()
{	
	sprite.SetImage(image);
	app->Draw(sprite);
}

void SpriteView::notify(Subject* s)
{
    WorldModel* m;
    m = dynamic_cast<WorldModel *>(s);
    sprite.SetPosition(m->get_x_position(), m->get_y_position());
	sprite.SetRotation((m->get_angle() * (180 / 3.14f)) * -1);
    draw();
}