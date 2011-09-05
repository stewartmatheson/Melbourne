/*
 *  ExitApplicationAction.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 14/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "ExitApplicationAction.h"

void ExitApplicationAction::action() { app->Close(); }