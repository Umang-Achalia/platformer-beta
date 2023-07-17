#pragma once

#include <SDL.h>
#include <iostream>
#include "Entity.h"
#include "Tile.h"
using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

class Game {
private:
	bool isRunning = false;

public:
	void init(const char*, int, int, int, int, int);
	void handleEvent();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
};
