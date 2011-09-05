/*
 *  SoundBite.cpp
 *  Melbourne
 *
 *  Created by Stewart Matheson on 16/04/10.
 *  Copyright 2010 Test. All rights reserved.
 *
 */

#include "Sound.h"

Sound::Sound(std::string const &f, float const p, float const v) : file_name(f), pitch(p), volume(v)
{
    buffer.LoadFromFile(file_name);
    sound.SetBuffer(buffer);
    sound.SetPitch(pitch);
    sound.SetVolume(volume);
}

void Sound::play(){ sound.Play(); } 