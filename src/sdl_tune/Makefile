CC	= gcc
SDL2_CFLAGS := $(shell sdl2-config --cflags)
SDL2_LDFLAGS := $(shell sdl2-config --libs)
#CFLAGS = -O3 -Wall -Winline -pipe -std=gnu99 $(SDL2_CFLAGS) -I./src/include
CFLAGS = -g -Wall -Winline -pipe -std=gnu99 $(SDL2_CFLAGS) -I./src/include
LDLIBS = $(SDL2_LDFLAGS) -lm -lSDL2_ttf

OBJS =  sdl_tune.o sdl.o event.o assets.o hud.o tune.o

sdl_tune: $(OBJS)
	@echo [link]
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	@echo "[Removing object files]"
	@find . -name '*.o' -delete
	@echo "[Removing binaries]"
	@rm -f dogfight
