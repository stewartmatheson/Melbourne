/*
 *  WallView.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "WallView.h"
#include "WorldModel.h"

WallView::WallView(sf::RenderWindow* a) : View(a){}

void const WallView::draw(){}

void WallView::notify(Subject* s)
{
    WorldModel* m;
    m = dynamic_cast<WorldModel *>(s);
}