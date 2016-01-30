#include <iostream>
#include <SDL.h>

using namespace std;

int main( int argc, char* argv[] ) {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		fprintf(stderr,
			"\nUnable to initialize SDL:  %s\n",
			SDL_GetError()
			);
		return 1;
	}

	SDL_Window* WINDOW;
	SDL_Renderer* RENDER;

	if (SDL_CreateWindowAndRenderer(640, 480, 0, &WINDOW, &RENDER)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 3;
	}

	SDL_Event event;

	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}
		
	}

	SDL_DestroyRenderer(RENDER);
	SDL_DestroyWindow(WINDOW);

	SDL_Quit();
	return 0;
}