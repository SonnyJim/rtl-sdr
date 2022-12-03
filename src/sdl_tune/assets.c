#include "sdl_tune.h"

int assets_init ()
{
	font = TTF_OpenFont("/usr/share/fonts/Sixteen-Mono.ttf", FONTSIZE);
	if (font == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't load font: %s", SDL_GetError());
		return 3;
	}
    	
	
	//SDL_FreeSurface(surface);
	return 0;
}

