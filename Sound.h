/*
 *  SoundBite.h
 *  Melbourne
 *
 *  Created by Stewart Matheson on 16/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 *  This class forms the basic wrapper for an SFML sound. It handles pitch and volume.
 */

#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <SFML/Audio.hpp>

class Sound 
{
    std::string file_name;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    float pitch, volume;
public:
    Sound(std::string const &f, float const p, float const v);
    void play();
};

#endif