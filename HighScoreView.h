/*
 *  HighScoreView.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 20/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#ifndef HIGH_SCORE_VIEW_H
#define HIGH_SCORE_VIEW_H

#include "View.h"
#include "Subject.h"

class HighScoreView : public View
{
    sf::String text;
public:
    HighScoreView::HighScoreView(sf::RenderWindow* a) : View(a) {};
    virtual void const draw();
    virtual void notify(Subject* s);
};

#endif