/*
 *  StarField.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "StarFieldView.h"

StarFieldView::StarFieldView(sf::RenderWindow* a) : View(a)
{
	for(int i = 0; i < 75; i++) 
		field.push_back(create_random_star());
}

sf::Shape StarFieldView::create_random_star()
{
	int xcord, ycord, brightness;
	xcord = sf::Randomizer::Random(-1500, 1500);
	ycord = sf::Randomizer::Random(-1500, 1500);
	brightness = sf::Randomizer::Random(0,128);
	sf::Color random_color(128,128,128, brightness);
	return sf::Shape::Circle(xcord, ycord, 1, sf::Color::White);
}

void const StarFieldView::draw()
{

}

void StarFieldView::notify(Subject* s)
{
    for(int i = 0; i < field.size(); i++)
		app->Draw(field[i]);
}

