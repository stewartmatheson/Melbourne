/*
 *  View.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 6/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "View.h"
#include "Model.h"

void View::notify(Subject* s)
{
    Model* m = dynamic_cast(s);
}