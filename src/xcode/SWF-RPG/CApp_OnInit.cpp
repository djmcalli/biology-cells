#include "CApp.h"
#include <iostream>

using namespace std;

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if (CArea::AreaControl.OnLoad("SWF-RPG.app/Contents/Resources/1.area") == false) {
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if (Player.OnLoad("SWF-RPG.app/Contents/Resources/player-2.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (Npc.OnLoad("SWF-RPG.app/Contents/Resources/dna-char.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (Npc2.OnLoad("SWF-RPG.app/Contents/Resources/dan-the-dna-man.png", 64, 64, 8) == false) {
        return false;
    }

    Npc.X = 150;
    Npc2.X = 150;
    Npc2.Dead = true;
    //Player2.Dead = true;
    //Player.Flags = 0;
    Npc.Y = 145;
    Npc2.Y = 85;

    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&Npc);
    CEntity::EntityList.push_back(&Npc2);

    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

    return true;
}
