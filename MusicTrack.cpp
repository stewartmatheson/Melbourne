/*
 *  MusicTrack.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 13/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "MusicTrack.h"

MusicTrack::MusicTrack(std::string const &file_name)
{
    track.OpenFromFile("test.ogg");
    
    //comment out during testing
    track.Play();
}

void MusicTrack::step()
{
    
}