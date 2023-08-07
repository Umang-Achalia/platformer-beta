#pragma once

#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "Camera.h"
using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern float speedX;
extern float speedY;
extern float shift_tile;

extern SDL_Rect intersect;
extern vector<Tile*> group_of_tiles;

extern Camera* hd;