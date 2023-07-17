#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

extern float speedX;
extern float speedY;

class Entity {
private:
	SDL_Texture* texture;
	SDL_Rect src, dest;

public:
	void loadTexture(const char*);
	void drawTexture(int, int);
	SDL_Rect* getRect() { return &dest; }
	~Entity() { SDL_DestroyTexture(texture); }
};
