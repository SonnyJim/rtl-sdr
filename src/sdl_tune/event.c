#include "sdl_tune.h"
int input_keyrepeat (void)
{
    if (input_repeat + 200 < SDL_GetTicks ())
    {
        input_repeat = SDL_GetTicks ();
        return 0;
    }
    return 1;
}


void event_read ()
{
	SDL_Event e;
	p1.buttons = 0;
	while (SDL_PollEvent(&e))
	{
		if( e.type == SDL_JOYAXISMOTION )
		{
			if( e.jaxis.axis == 0 )
			{
				if( e.jaxis.value < -DEADZONE )
				{
					p1.inpx = e.jaxis.value;

                                }
                                //Right of dead zone
                                else if( e.jaxis.value > DEADZONE )
                                {
					p1.inpx = e.jaxis.value;
                                }
                                else
                                {
					p1.inpx = 0;
                                }			
			}
			else if( e.jaxis.axis == 1 )
			{
				if( e.jaxis.value < -DEADZONE )
				{
					p1.inpy = e.jaxis.value;

                                }
                                //Right of dead zone
                                else if( e.jaxis.value > DEADZONE )
                                {
					p1.inpy = e.jaxis.value;
                                }
                                else
                                {
					p1.inpy = 0;
                                }			
			}

		}

		if (e.type == SDL_JOYBUTTONDOWN)
		{
			if (e.jbutton.button == 0)
			{
				p1.buttons |= 1;

				fprintf (stdout, "BUTTON %i\n", p1.buttons);
			}

			if (e.jbutton.button == 1)
			{
				p1.buttons |= 1 << 1;

				fprintf (stdout, "BUTTON %i\n", p1.buttons);
			}
		}

	}
	hud_handle_input ();
}
