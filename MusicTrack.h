/*
 *  MusicTrack.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 13/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class is the basic wrapper for the music track in SFML. Its used by the 
 *  game to play music.
 */


#ifndef MUSIC_TRACK_H
#define MUSIC_TRACK_H

#include <SFML/Audio.hpp>
#include <string>
#include "Model.h"

class MusicTrack : public Model
{
    sf::Music track;
public:
    MusicTrack(std::string const &file_name);
    virtual void step();
};

#endif