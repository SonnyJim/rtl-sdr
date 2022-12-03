#include "sdl_tune.h"

int sdl_init (void)
{
	//INIT Video
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) 
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}

	if (SDL_CreateWindowAndRenderer(SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_FULLSCREEN, &window, &renderer)) 
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 3;
	}
	
	if (SDL_NumJoysticks() < 1)
	{
		fprintf (stderr, "Unable to find any joysticks\n");
		return 3;
	}
	else
	{
		joystick = SDL_JoystickOpen (0);
		if (joystick == NULL)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
			return 3;
		}
	}
	TTF_Init();
	return 0;
}

void sdl_destroy ()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	if (SDL_JoystickGetAttached(joystick)) 
		SDL_JoystickClose(joystick);
	TTF_Quit();
	SDL_Quit();
}
