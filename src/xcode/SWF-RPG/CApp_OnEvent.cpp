#include "CApp.h"
#include <iostream>

void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

void CApp::OnExit() {
	Running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch (sym) {
		case SDLK_LEFT: {
			Player.MoveLeft = true;
			break;
		}

		case SDLK_RIGHT: {
			Player.MoveRight = true;
			break;
		}

		case SDLK_UP: {
			Player.MoveUp = true;
			break;
		}

		case SDLK_DOWN: {
			Player.MoveDown = true;
			break;
		}

		default: {
		}
	}
}

void CApp::OnLButtonDown(int x, int y) {
    if (Player.showGUI == true) {
        if ((x >= 284 && x <= 360) && (y >= 90 && y < 140)) {
            std::cout << "Clicked 1";
            Player.brendenPart(1);
            Player.showGUI = false;
            Player.canMove = false;
        }
        else if ((x >= 284 && x <= 360) && (y >= 140 && y < 210)) {
            std::cout << "Clicked 2";
            Player.brendenPart(2);
            Player.showGUI = false;
            Player.canMove = false;
        }
        else if ((x >= 284 && x <= 360) && (y >= 210 && y < 270)) {
            std::cout << "Clicked 3";
            Player.brendenPart(3);
            Player.showGUI = false;
            Player.canMove = false;
        }
        else if ((x >= 284 && x <= 360) && (y >= 272 && y < 330)) {
            std::cout << "Clicked 4";
            Player.brendenPart(4);
            Player.showGUI = false;
            Player.canMove = false;
        }
        else if ((x >= 284 && x <= 360) && (y >= 330 && y < 391)) {
            std::cout << "Clicked 5";
            Player.brendenPart(5);
            Player.showGUI = false;
            Player.canMove = false;
        }
        else if ((x >= 284 && x <= 360) && (y >= 391 && y < 451)) {
            std::cout << "Clicked All";
            Player.brendenPart(0);
            Player.showGUI = false;
            Player.canMove = false;
        }
    }
    std::cout << "Left Mouse Click" << " x:" << x << " y:" << y << "\n";
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch (sym) {
		case SDLK_LEFT: {
			Player.MoveLeft = false;
			break;
		}

		case SDLK_RIGHT: {
			Player.MoveRight = false;
			break;
		}

		case SDLK_UP: {
			Player.MoveUp = false;
			break;
		}

		case SDLK_DOWN: {
			Player.MoveDown = false;
			break;
		}

		default: {
		}
	}
}
