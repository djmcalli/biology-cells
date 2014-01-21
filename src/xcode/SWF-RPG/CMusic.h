//
//  CMusic.h
//  SWF-RPG
//
//  Created by Dylan McAllister on 12/5/13.
//  Copyright (c) 2013 Sea Water Fox. All rights reserved.
//

#ifndef __SWF_RPG__CMusic__
#define __SWF_RPG__CMusic__

#include <SDL/SDL.h>
#include <SDL_mixer/SDL_mixer.h>
#include <iostream>
using namespace std;

class CMusic {
    
    public:
        static CMusic MusicControl;
    
    public:
        CMusic();
    
        Mix_Music *music;
    
        bool    OnPlay(string File);
        void    musicFinished();
        void    cleanUp();
};

#endif