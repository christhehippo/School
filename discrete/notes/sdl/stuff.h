#ifndef  _STUFF_H
#define  _STUFF_H

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface *load_image(char *);
void apply_surface(int, int, SDL_Surface *, SDL_Surface *);

#endif
