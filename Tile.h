#pragma once

#include <SDL.h>

class Tile {
private:
	SDL_Rect tile;

public:
	Tile(int, int);
	void drawTile();
	SDL_Rect* getTile() { return &tile; }
};
