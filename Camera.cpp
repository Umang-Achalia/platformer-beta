#include "Camera.h"
#include "ExternDecl.h"

void Camera::drawCam() {
	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 1);
	SDL_RenderDrawRect(gRenderer, &rect);
}