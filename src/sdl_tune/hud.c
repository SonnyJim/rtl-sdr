#include "sdl_tune.h"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <dirent.h>

int fontwidth;
int old_freq;

char demod_str[4][4] = {{"FM"}, {"AM"}, {"USB"}, {"LSB"}};
static void hud_render_text (char *str, int x, int y)
{
	SDL_Rect rect;
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface *surface = TTF_RenderText_Solid(font,str, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_GetClipRect (surface, &rect);
	rect.x = x;
	rect.y = y;
	SDL_FreeSurface (surface);
	SDL_RenderCopy (renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}

static void hud_draw_selection (void)
{
	SDL_Rect rect;
	rect.x = (SCREENWIDTH / 2) + ((fontwidth) * current_selection) -  (5 * fontwidth);
	rect.y = SCREENHEIGHT /2 + FONTSIZE;
	rect.w = fontwidth;
	rect.h = 20;

	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderDrawRect (renderer, &rect);
}

static void hud_draw_status (void)
{
	char buffer[10];
	sprintf (buffer, "%09d", current_freq);
	TTF_SizeText(font, "0", &fontwidth, NULL);
	hud_render_text (buffer, (SCREENWIDTH / 2) - (5 * fontwidth), SCREENHEIGHT / 2);
	hud_render_text (demod_str[demod], (SCREENWIDTH / 2) - (5 * fontwidth), 0);
	
	hud_draw_selection ();
}


static void hud_update_freq (void)
{
	if (old_freq != current_freq)
	{
		old_freq = current_freq;
		send_freq (current_freq);
	}
}

void hud_draw (void)
{
	hud_draw_status ();
	hud_update_freq ();
}

#define FARTS 100000

static int hud_get_offset (void)
{
	return pow(10, (10 - current_selection));
}
static void hud_bounds_check (void)
{
	if (current_freq > 2000000000)
		current_freq = 2000000000;
	else if (current_freq < 60000000)
		current_freq = 60000000;
}
static void hud_increment_freq (void)
{
	current_freq += hud_get_offset();
	hud_bounds_check ();
}

static void hud_decrement_freq (void)
{
	current_freq -= hud_get_offset();
	hud_bounds_check ();
}

void hud_handle_input ()
{
	/*
	*/
	if (p1.inpy < -DEADZONE)
	{
		hud_increment_freq ();

	}
	else if (p1.inpy > DEADZONE)
	{
		hud_decrement_freq ();
	}

	if (p1.inpx < -DEADZONE)
	{
		if (input_keyrepeat ())
			return;
		if (current_selection > 0)
			current_selection -=  1;
	}
	else if (p1.inpx > DEADZONE)
	{
		if (input_keyrepeat ())
			return;
		if (current_selection < 8)
			current_selection++;
	}



	if ( p1.buttons == 2)
	{
		change_demod ();
	}
	if (p1.buttons == 1)
	{
		running = 0;
	}
}
