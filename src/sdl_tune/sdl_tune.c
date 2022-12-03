#include "sdl_tune.h"
#include <signal.h>

void intHandler (int dummy)
{
	running = 0;
}

int main(int argc, char *argv[])
{
	signal(SIGINT, intHandler);
    if (sdl_init () != 0 || assets_init () != 0)
    {
	fprintf (stderr, "Unable to initialise :(\n");
	return 1;
    }

	running = 1;    
	current_freq = 99300000;
    while (running) 
    {
	event_read ();
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0x00);
        SDL_RenderClear(renderer);
	hud_draw ();
        SDL_RenderPresent(renderer);
    }
	sdl_destroy ();
    return 0;
}
