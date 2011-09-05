/*
 *  HighScoreView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 20/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "HighScoreView.h"

#include "Player.h"
#include <sstream>

void const HighScoreView::draw()
{
}

void HighScoreView::notify(Subject* s)
{
    Player* p;
    p = dynamic_cast<Player *>(s);    
    std::stringstream ss;
    ss << "High Score: " << p->get_high_score();
    text.SetText(ss.str());
    text.SetSize(26); 
    text.SetPosition(p->get_x_position() - 350, p->get_y_position() - 350);
    app->Draw(text);
}