#include "dogfight.h"
#include <math.h>

void move_players (void)
{
	/*
	if (p1.inpx < 0)
		p1.rot -= 1;
	else if (p1.inpx > 0)
		p1.rot += 1;
	if (p1.rot > 360)
		p1.rot = 1;
	else if (p1.rot < 0)
		p1.rot = 360;
		*/
//	p1.pos.x += p1.speed;
	
	p1.pos.x += p1.speed * sin(p1.rot);
	p1.pos.y += p1.speed * cos(p1.rot);
	
	if (p1.pos.x >  SCREENWIDTH)
		p1.pos.x -= SCREENWIDTH;
	if (p1.pos.x < 0)
		p1.pos.x += SCREENWIDTH;
	if (p1.pos.y >  SCREENHEIGHT)
		p1.pos.y -= SCREENHEIGHT;
	if (p1.pos.y < 0)
		p1.pos.y += SCREENHEIGHT;
}

