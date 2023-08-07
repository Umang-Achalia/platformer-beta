#include "Camera.h"
#include "ExternDecl.h"

Camera::Camera() {
	view = { 0, 0, 950, 550 };
}

void Camera::drawView() {
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 1);
	SDL_RenderDrawRect(gRenderer, &view);
}