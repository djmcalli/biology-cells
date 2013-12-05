#include "CApp.h"

void CApp::OnCleanup() {
    for (int i = 0; i < CEntity::EntityList.size(); i++) {
        if (!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnCleanup();
    }
    CEntity::EntityList.clear();

    CArea::AreaControl.OnCleanup();
    CMusic::MusicControl.cleanUp();

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
