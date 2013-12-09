#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include "CEntity.h"

class CPlayer : public CEntity {
    protected:
        SDL_Surface*    GUI;
    
    public:
        CPlayer();

		bool OnLoad(char* File, int Width, int Height, int MaxFrames);
    
        bool showGUI;

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        void OnCollision(CEntity* Entity);
    
        void brendenPart(int num);
};

#endif
