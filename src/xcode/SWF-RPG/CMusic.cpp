//
//  CMusic.cpp
//  SWF-RPG
//
//  Created by Dylan McAllister on 12/5/13.
//  Copyright (c) 2013 Sea Water Fox. All rights reserved.
//

#include "CMusic.h"

CMusic CMusic::MusicControl;
bool    musicPlaying;

CMusic::CMusic() {
    
}

void musicFinished() {
    printf("Music stopped.\n");
    
    musicPlaying = false;
}

void bbMusicFinished()
{
    musicFinished();
}

void setMusicPlaying(bool mP) {
    musicPlaying = mP;
}

bool CMusic::OnPlay(char* File) {
    int audio_rate = 44100;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channel = 2;
    int audio_buffer = 2048;
    
    if (Mix_OpenAudio(audio_rate, audio_format, audio_channel, audio_buffer) != 0) {
        fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
        return false;
    }
    
    
    music = Mix_LoadMUS(File);
    if (music == NULL) {
        // This is where the error occurs.
        fprintf(stderr, "Unable to load mp3 file: %s\n", Mix_GetError());
        return false;
    }
    
    if (Mix_PlayMusic(music, 0) == -1)
    {
        fprintf(stderr, "Unable to play mp3 file: %s\n", Mix_GetError());
        return false;
    }
    
    musicPlaying = true;
    Mix_HookMusicFinished(bbMusicFinished);
    
    return true;
}

void CMusic::cleanUp() {
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}