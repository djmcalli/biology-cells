//
//  CTalkNPC.cpp
//  SWF-RPG
//
//  Created by Dylan McAllister on 12/4/13.
//  Copyright (c) 2013 Sea Water Fox. All rights reserved.
//

#include "CTalkNPC.h"

CTalkNPC::CTalkNPC() {
}

bool CTalkNPC::OnLoad(string File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }
    
    //Flags = ENTITY_FLAG_NONE;
    
    return true;
}

void CTalkNPC::OnLoop() {
	CEntity::OnLoop();
}

void CTalkNPC::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

void CTalkNPC::OnCleanup() {
	CEntity::OnCleanup();
}

void CTalkNPC::OnAnimate() {
	Anim_Control.MaxFrames = 1;
    CurrentFrameCol = 0;
    
	CEntity::OnAnimate();
}

void CTalkNPC::OnCollision(CEntity* Entity) {
}
