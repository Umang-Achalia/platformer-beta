#include "Tile.h"
#include <SDL_image.h>
#include "ExternDecl.h"
using namespace std;

Tile::Tile(int x, int y) {
	tile.x = x;
	tile.y = y;
	tile.w = 50;
	tile.h = 50;
}

void Tile::drawTile() {
	tile.x += shift_tile;
	SDL_SetRenderDrawColor(gRenderer, 60, 82, 145, 1);
	SDL_RenderDrawRect(gRenderer, &tile);
	SDL_RenderFillRect(gRenderer, &tile);
}