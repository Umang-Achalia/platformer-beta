#include "Tile.h"

void Tile::drawTile(int x, int y) {
	tile.x = x;
	tile.y = y;
	tile.w = 90;
	tile.h = 30;

	SDL_SetRenderDrawColor(gRenderer, 224, 165, 38, 1);
	SDL_RenderDrawRect(gRenderer, &tile);
	SDL_RenderFillRect(gRenderer, &tile);
}

bool Tile::isColliding(SDL_Rect* player) {
	int right, right2;
	int left, left2;
	int top, top2;
	int bottom, bottom2;

	right = tile.x + tile.w;
	left = tile.x;
	top = tile.y;
	bottom = tile.y + tile.h;

	right2 = player->x + player->w;
	left2 = player->x;
	top2 = player->y;
	bottom2 = player->y + player->h;

	/*if (SDL_HasIntersection(&tile, player)) {
		return true;
	}
	return false;*/

	if (bottom2 <= top || top2 >= bottom || right2 <= left || left >= right) {
		return false;
	}
	return true;
}