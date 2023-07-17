#pragma once

#include <SDL.h>
#include "Entity.h"
#include <SDL_image.h>
#include <iostream>
using namespace std;

class Tile {
private:
	SDL_Rect tile;

public:
	void drawTile(int, int);
	bool isColliding(SDL_Rect*);
};
