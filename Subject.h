/*
 *  Subject.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the subject class that forms the base of the model class. This class
 *  is used to send messages to the views or observers of the models in the game.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject
{
	std::vector<Observer*> observers;
protected:
	void notify_observers();
public:
	virtual ~Subject(){};
	void register_observer(Observer* o);
    void detatch_observers();
};

#endif