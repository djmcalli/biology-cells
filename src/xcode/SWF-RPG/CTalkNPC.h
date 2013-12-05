//
//  CTalkNPC.h
//  SWF-RPG
//
//  Created by Dylan McAllister on 12/4/13.
//  Copyright (c) 2013 Sea Water Fox. All rights reserved.
//
#ifndef SWF_RPG_CTalkNPC_h
#define SWF_RPG_CTalkNPC_h

#include "CEntity.h"

class CTalkNPC : public CEntity {
public:
    CTalkNPC();
    
    bool OnLoad(char* File, int Width, int Height, int MaxFrames);
    
    void OnLoop();
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();
    
    void OnAnimate();
    
    void OnCollision(CEntity* Entity);
};

#endif