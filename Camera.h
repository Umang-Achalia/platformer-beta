#pragma once

#include <SDL.h>

class Camera {
private:
	SDL_Rect view;

public:
	Camera();
	SDL_Rect* getViewbox() { return &view; }
	void drawView();
};