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

    if (CArea::AreaControl.OnLoad("Cells.app/Contents/Resources/1.area") == false) {
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
    
    if (Npc.OnLoad("Cells.app/Contents/Resources/dna-char.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (NpcName.OnLoad("Cells.app/Contents/Resources/dan-the-dna-man.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (Brenden.OnLoad("Cells.app/Contents/Resources/brenden.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (BrendenName.OnLoad("Cells.app/Contents/Resources/brenden-name.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (Erica.OnLoad("Cells.app/Contents/Resources/erica.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (EricaName.OnLoad("Cells.app/Contents/Resources/erica-name.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (Laurie.OnLoad("Cells.app/Contents/Resources/laurie.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (LaurieName.OnLoad("Cells.app/Contents/Resources/laurie-name.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (Player.OnLoad("Cells.app/Contents/Resources/player-2.png", 64, 64, 8) == false) {
        return false;
    }
    
    Npc.X = 150;
    NpcName.X = 150;
    Brenden.X = 150;
    BrendenName.X = 150;
    
    Erica.X = 790;
    EricaName.X = 790;
    Laurie.X = 790;
    LaurieName.X = 790;
    
    NpcName.Dead = true;
    BrendenName.Dead = true;
    EricaName.Dead = true;
    LaurieName.Dead = true;
    
    Npc.Y = 145;
    NpcName.Y = 85;
    Laurie.Y = 145;
    LaurieName.Y = 85;
    
    Brenden.Y = 783;
    BrendenName.Y = 725;
    Erica.Y = 785;
    EricaName.Y = 725;
    
    Npc.eid = 1;
    Brenden.eid = 2;
    Erica.eid = 3;
    Laurie.eid = 4;
    
    CMusic::MusicControl.OnPlay("Cells.app/Contents/Resources/dandna.ogg");

    CEntity::EntityList.push_back(&Npc);
    CEntity::EntityList.push_back(&NpcName);
    CEntity::EntityList.push_back(&Brenden);
    CEntity::EntityList.push_back(&BrendenName);
    CEntity::EntityList.push_back(&Erica);
    CEntity::EntityList.push_back(&EricaName);
    CEntity::EntityList.push_back(&Laurie);
    CEntity::EntityList.push_back(&LaurieName);
    CEntity::EntityList.push_back(&Player);

    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

    return true;
}
