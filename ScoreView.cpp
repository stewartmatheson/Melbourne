/*
 *  ScoreView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 17/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "ScoreView.h"
#include "Player.h"
#include <sstream>

void const ScoreView::draw()
{
}

void ScoreView::notify(Subject* s)
{
    Player* p;
    p = dynamic_cast<Player *>(s);    
    std::stringstream ss;
    ss << "Score: " << p->get_score();
    text.SetText(ss.str());
    text.SetSize(26); 
    text.SetPosition(p->get_x_position() - 550, p->get_y_position() - 350);
    app->Draw(text);
}