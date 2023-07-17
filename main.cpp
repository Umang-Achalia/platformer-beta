#include "Game.h"

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 400;

Game* game = nullptr;

const int FPS = 60;
int desired_delta = 1000 / FPS;

int main(int num_args, char* argv[]) {
	int start_loop, delta;

	game = new Game();
	game->init("SDL EXP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	while (game->running()) {
		start_loop = SDL_GetTicks();

		game->handleEvent();
		game->render();
		game->update();

		delta = SDL_GetTicks() - start_loop;

		if (delta < desired_delta) {
			SDL_Delay(desired_delta - delta);
		}
	}
	game->clean();
	return 0;
}