#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer() {
}

bool CPlayer::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    //Flags = ENTITY_FLAG_NONE;

    return true;
}

void CPlayer::OnLoop() {
	CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

void CPlayer::OnCleanup() {
	CEntity::OnCleanup();
}

void CPlayer::OnAnimate() {
	if ((SpeedX != 0 || SpeedY != 0) && !(canMove)) {
		Anim_Control.MaxFrames = 3;
	} else {
		Anim_Control.MaxFrames = 0;
	}

	CEntity::OnAnimate();
}

void CPlayer::OnCollision(CEntity* Entity) {
    switch (Entity->eid) {
        case 1:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/dandna.ogg");
            break;
        case 2:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/bullseye.ogg");
            break;
        default:
            
            break;
    }
    std::cout << "Collided!: " << Entity->Type << " " << "ID: " << Entity->eid << "\n";
    
    //canMove = true;
}
