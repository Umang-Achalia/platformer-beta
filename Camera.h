#pragma once

#include <SDL.h>

class Camera {
private:
	float x, y;
public:
	void setPos(float xP, float yP) { x = xP, y = yP; }
	float getX() { return x; }
	float getY() { return y; }
};