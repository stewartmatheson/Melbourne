/*
 *  ExitApplicationAction.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This action kills the application.
 */

#ifndef EXIT_APPLICATION_ACTION_H
#define EXIT_APPLICATION_ACTION_H

#include <SFML/Graphics.hpp>
#include "MenuItemAction.h"


class ExitApplicationAction : public MenuItemAction
{
public:
    ExitApplicationAction(sf::RenderWindow* a) : MenuItemAction(a) {}
    virtual void action();
};

#endif