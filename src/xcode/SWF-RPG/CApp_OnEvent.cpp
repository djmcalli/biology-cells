#include "CApp.h"

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
