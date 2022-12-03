#define SCREENWIDTH 640
#define SCREENHEIGHT 480
#define DEADZONE 8000

#define FONTSIZE 60
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct player
{
	int inpx;
	int inpy;
	uint8_t buttons;
};

struct player p1;
int running;
int current_freq;
int current_selection;
int demod; //current demod

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Joystick *joystick;
TTF_Font *font;
int input_keyrepeat (void);
int input_repeat;
int sdl_init (void);
void sdl_destroy (void);
int assets_init (void);
void event_read (void);

void move_players (void);
void hud_draw (void);
void hud_handle_input (void);

void send_freq (int freq);
void change_demod (void);

