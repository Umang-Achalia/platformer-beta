#include "Entity.h"

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

	dest.w = src.w * 2.6;
	dest.h = src.h * 2.6;

	SDL_RenderCopy(gRenderer, texture, &src, &dest);
}