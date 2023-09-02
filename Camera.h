#pragma once

#include <SDL.h>

class Camera {
private:
	SDL_Rect rect;
public:
	void setPos(float xP, float yP) { rect.x = xP, rect.y = yP, rect.w = 950, rect.h = 550; }
	SDL_Rect* getRect() { return &rect; }
	void drawCam();
};