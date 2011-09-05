/*
 *  ScoreView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 17/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  The view that prints the text out for the score. Use by the player class.
 */

#ifndef SCORE_VIEW_H
#define SCORE_VIEW_H

#include "View.h"
#include "Subject.h"

class ScoreView : public View
{
    sf::String text;
public:
    ScoreView::ScoreView(sf::RenderWindow* a) : View(a) {};
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif