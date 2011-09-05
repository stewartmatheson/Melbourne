/*
 *  ContactListener.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 15/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class handles the contacts in the physics world and calls the collide 
 *  memeber functions on the models when there is a collision in the physics world.
 */

#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include "Box2D.h"

class ContactListener : public b2ContactListener
{
public:    
    virtual void Add(const b2ContactPoint* point);   
};

#endif