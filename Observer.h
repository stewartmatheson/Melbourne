/*
 *  Observer.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 5/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This is the base class for the observer. Its pure virtual and is only used by
 *  the view class.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer
{
public:
	virtual void notify(Subject* s) = 0;
	virtual ~Observer(){};
};

#endif