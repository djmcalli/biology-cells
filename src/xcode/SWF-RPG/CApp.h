#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>

#include "Define.h"

#include "CAnimation.h"
#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"
#include "CPlayer.h"
#include "CSurface.h"
#include "CTalkNPC.h"
#include "CMusic.h"

class CApp : public CEvent {
    private:
        bool            MusicRunning;
        bool            Running;

        SDL_Surface*    Surf_Display;

        CPlayer			Player;
        CTalkNPC		Npc;
        CTalkNPC		NpcName;
        CTalkNPC		Brenden;
        CTalkNPC		BrendenName;
        CTalkNPC		Erica;
        CTalkNPC		EricaName;
        CTalkNPC		Laurie;
        CTalkNPC		LaurieName;

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
    
            void OnLButtonDown(int x, int y);

            void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

#endif
