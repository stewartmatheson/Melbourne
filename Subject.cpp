/*
 *  Subject.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Subject.h"

void Subject::notify_observers()
{	
	std::vector<Observer* >::iterator iter;
	for (iter = observers.begin(); iter != observers.end(); ++iter)
		(*iter)->notify(this);
}

void Subject::register_observer(Observer* o)
{
	observers.push_back(o);
}

void Subject::detatch_observers()
{  
	std::vector<Observer* >::iterator iter;
	for (iter = observers.begin(); iter != observers.end(); ++iter)
		delete (*iter);    
    observers.empty();
}