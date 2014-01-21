#ifndef _CAREA_H_
    #define _CAREA_H_

#include "CMap.h"

using namespace std;

class CArea {
    public:
        static CArea            AreaControl;

    public:
        std::vector<CMap>       MapList;

    private:
        SDL_Surface*        Surf_Tileset;

    public:
        CArea();

        bool    OnLoad(string File);

        int     AreaSize;

        void    OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);

        void    OnCleanup();

    public:
        CMap*    GetMap(int X, int Y);

        CTile*    GetTile(int X, int Y);
};

#endif
