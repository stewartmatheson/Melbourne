/*
 *  View.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "View.h"

View::View(sf::RenderWindow* a)
{
    app = a;
}

bool View::is_disposed() { return disposed; }
void View::dispose() {disposed = true; }