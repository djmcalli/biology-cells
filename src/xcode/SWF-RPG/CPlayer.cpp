#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer() {
}

bool CPlayer::OnLoad(string File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    //Flags = ENTITY_FLAG_NONE;
    showGUI = false;

    return true;
}

void CPlayer::OnLoop() {
	CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
    
    if (showGUI) {
        if ((GUI = CSurface::OnLoad("Cells.app/Contents/Resources/cells_gui-aspectselect.png")) == NULL) {
            return;
        }
        CSurface::OnDraw(Surf_Display, GUI, 15, 10, 0, 0, 620, 460);
    }
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

void CPlayer::brendenPart(int num) {
    switch (num) {
        case 0:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-recording.ogg");
            break;
            
        case 1:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-1.ogg");
            break;
            
        case 2:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-2.ogg");
            break;
            
        case 3:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-3.ogg");
            break;
            
        case 4:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-4.ogg");
            break;
            
        case 5:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-5.ogg");
            break;
    }
}

void CPlayer::OnCollision(CEntity* Entity) {
    switch (Entity->eid) {
        case 1:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/dandna.ogg");
            break;
        case 2:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/brenden-overview.ogg");
            showGUI = true;
            canMove = true;
            break;
        case 3:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/erica-recording.ogg");
            break;
        case 4:
            CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/laurie-recording.ogg");
            break;
        default:
            
            break;
    }
    
    std::cout << "Collided!: " << Entity->Type << " " << "ID: " << Entity->eid << "\n";
}