#include "Tile.h"
#include <SDL_image.h>
#include "ExternDecl.h"
using namespace std;

Tile::Tile(int x, int y, const char* path) {
	texture = IMG_LoadTexture(gRenderer, path);

	src.x = 0;
	src.y = 0;
	src.w = 16;
	src.h = 16;

	tile.x = x;
	tile.x -= shift_tile;
	tile.y = y;
	tile.w = src.w * 3.125;
	tile.h = src.h * 3.125;

}

void Tile::drawTile() {
	SDL_RenderCopy(gRenderer, texture, &src, &tile);
}