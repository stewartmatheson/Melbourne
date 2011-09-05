/*
 *  State.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 13/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "State.h"

bool State::is_next_state() { return next_state; } 
void State::finished() { next_state = true; }