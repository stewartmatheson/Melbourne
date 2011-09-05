/*
 *  ContactListener.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 15/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "ContactListener.h"
#include "WorldModel.h"

void ContactListener::Add(const b2ContactPoint* point)
{
    WorldModel* wm1;
    WorldModel* wm2;
    wm1 = static_cast<WorldModel *>(point->shape1->GetBody()->GetUserData());
    wm2 = static_cast<WorldModel *>(point->shape2->GetBody()->GetUserData());
    wm1->collide(wm2);
    wm2->collide(wm1);
}