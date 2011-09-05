/*
 *  Model.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the base model class. This class is used to dispatch the update messages
 *  to the views via the subject class. This class also handles the disposing of game models 
 *  during run time with the use of the disposed flag.
 */

#ifndef MODEL_H
#define MODEL_H

#include "Subject.h"

class Model : public Subject
{
    bool disposed;
public:
    Model() : disposed(false) {};
	virtual void step() = 0;
    bool is_disposed();
    void dispose();
};

#endif