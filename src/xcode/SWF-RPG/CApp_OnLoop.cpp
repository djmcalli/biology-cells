#include "CApp.h"

void CApp::OnLoop() {
    for (int i = 0;i < CEntity::EntityList.size();i++) {
        if (!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

    CFPS::FPSControl.OnLoop();

    char Buffer[249];
    sprintf(Buffer, "%d", CFPS::FPSControl.GetFPS());
    char T[20] = "[Cell Project] FPS:";
    char BB[255];
    sprintf(BB, "%s %s", T, Buffer);
    SDL_WM_SetCaption(BB, Buffer);
}
