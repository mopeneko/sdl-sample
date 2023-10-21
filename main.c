#include "SDL.h"

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("failed to initialize SDL: %s", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow(
			"SampleWindow",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			SDL_WINDOW_OPENGL
			);

	if (window == NULL)
	{
		SDL_Log("failed to create window: %s\n", SDL_GetError());
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		SDL_Log("failed to create render: %s\n", SDL_GetError());
	}

	while (1)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_DestroyWindow(window);
				SDL_Quit();
				return 0;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_Rect wall;
		wall.x = 100;
		wall.y = 100;
		wall.w = 100;
		wall.h = 100;
		SDL_RenderFillRect(renderer, &wall);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
