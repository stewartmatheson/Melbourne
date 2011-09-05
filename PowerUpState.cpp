/*
 *  PowerUpState.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 18/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "PowerUpState.h"

float const PowerUpState::get_firespeed_modifier(){ return firespeed_modifier; }
void PowerUpState::set_firespeed_modifier(float const f) { firespeed_modifier = f; }