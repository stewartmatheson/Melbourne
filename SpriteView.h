/*
 *  SpriteView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The sprite view class handles the displaying of an image. It takes a file name
 *  and will display any image that can be loaded in to sfml.
 */

#ifndef SPRITEVIEW_H
#define SPRITEVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "View.h"
#include "Subject.h"

class SpriteView : public View
{	
public:
    SpriteView(sf::RenderWindow* a);
	virtual void const draw();
    virtual void notify(Subject* s);
protected:
	sf::Image image;
	sf::Sprite sprite;
	void init_sprite(std::string const &file_name);
};

#endif