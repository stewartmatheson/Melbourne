/*
 *  Model.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 16/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Model.h"

bool Model::is_disposed() { return disposed; }
void Model::dispose() { disposed = true; }