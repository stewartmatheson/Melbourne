/*
 *  EnergyView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 19/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "EnergyView.h"
#include "Player.h"
#include <sstream>

void const EnergyView::draw(){}
void EnergyView::notify(Subject* s)
{
    Player* p;
    p = dynamic_cast<Player *>(s);    
    std::stringstream ss;
    ss << "Energy: " << p->get_energy();
    text.SetText(ss.str());
    text.SetSize(26); 
    text.SetPosition(p->get_x_position() + 400, p->get_y_position() - 350);
    app->Draw(text);
}