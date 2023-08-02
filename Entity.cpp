#include "Entity.h"
#include <SDL_image.h>
#include "ExternDecl.h"

void Entity::loadTexture(const char* path){
	texture = IMG_LoadTexture(gRenderer, path);
}

void Entity::drawTexture(int x, int y) {
	src.x = 0;
	src.y = 0;
	src.w = 15;
	src.h = 17;

	dest.x = x;
	dest.x += speedX;

	dest.y = y;
	dest.y += speedY;

	dest.w = src.w * 3;
	dest.h = src.h * 3;

	vertical_detector.x = dest.x + 9;
	vertical_detector.y = dest.y - 3;
	vertical_detector.w = 27;
	vertical_detector.h = 54;

	horizontal_detector.x = dest.x;
	horizontal_detector.y = dest.y + 9;
	horizontal_detector.w = 45;
	horizontal_detector.h = 18;

	SDL_RenderCopy(gRenderer, texture, &src, &dest);
}