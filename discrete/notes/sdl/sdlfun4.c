#include "stuff.h"

int main()
{
	SDL_Surface *img	 = NULL;  // image (to put on background)
	SDL_Surface *bg      = NULL;  // background
	SDL_Surface *screen  = NULL;  // screen/window

	int width			 = 1600;  // width (in pixels)
	int height			 = 1200;  // height
	int bpp 			 = 32;    // bits per pixel (color depth)

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		exit(1);
	}

	screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);
	if (screen == NULL)
	{
		exit(2);
	}

	SDL_WM_SetCaption("Moar Images", NULL);

	img = load_image("dog.png");
	bg  = load_image("bg.jpg");
	
	apply_surface(0, 0, bg, screen);
	apply_surface(width/2, height/2, img, screen);

	if (SDL_Flip(screen) == -1)
	{
		exit(3);
	}

	SDL_Delay(5000);

	SDL_FreeSurface(img);
	SDL_FreeSurface(bg);

	SDL_Quit();

	return(0);
}	
