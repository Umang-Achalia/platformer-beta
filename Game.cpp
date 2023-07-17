#include "Game.h"

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

// HORIZONTAL
float speedX = 2.0f;
float rt_runStr = 8.5f;
float lt_runStr = 8.5f;
float maxX = 15.5f;

// VERTICAL
float speedY = 0.0f;
float gravity = 2.2f;
float jumpStr = 12.2f;

// flags
int rightK = 0;
int leftK = 0;
int up = 0;
int collision = 1;

Entity* player = nullptr;

Tile* newT = nullptr;

void Game::init(const char* title ,int x, int y, int w, int h, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		// create window
		gWindow = SDL_CreateWindow(title, x, y, w, h, flags);

		if (gWindow != NULL) {

			// create renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

			isRunning = true;
		}
		else {
			isRunning = false;
		}
	}
	else {
		isRunning = false;
	}
	player = new Entity;
	player->loadTexture("assets/doux_00.png");
	newT = new Tile;
}

void Game::handleEvent() {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {

		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
}

void Game::update() {
	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_d)]) {
		rightK = 1;
		lt_runStr = 0.0f;
		rt_runStr += 0.6f;
	}
	else {
		rightK = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_a)]) {
		leftK = 1;
		rt_runStr = 0.0f;
		lt_runStr += 0.6f;
	}
	else {
		leftK = 0;
	}

	if (SDL_GetKeyboardState(0)[SDL_GetScancodeFromKey(SDLK_SPACE)]) {
		up = 1;
		gravity = 0;
	}
	else {
		up = 0;
	}

	if (rt_runStr >= maxX) {
		rt_runStr = maxX;
		lt_runStr = 0.0f;
	}

	if (lt_runStr >= maxX) {
		lt_runStr = maxX;
		rt_runStr = 0.0f;
	}

	if (newT->isColliding(player->getRect())) {
		collision = 0;
		gravity = 0;
	}
	else {
		collision = 1;
	}

	speedX += (rightK * rt_runStr) - (leftK * lt_runStr);
	gravity += 0.6f;
	speedY += (collision * gravity) - (up * jumpStr);
}

void Game::render() {
	SDL_RenderClear(gRenderer);
	// ------------------------------------------
	
	player->drawTexture(350, 50);
	newT->drawTile(350, 300);

	// ------------------------------------------
	SDL_SetRenderDrawColor(gRenderer, 67, 70, 75, 1);
	SDL_RenderPresent(gRenderer);
}

void Game::clean() {
	delete player;
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}