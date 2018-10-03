#include "stuff.h"

int main()
{
	SDL_Event    event;
	
	SDL_Surface *img	 = NULL;  // image (to put on background)
	SDL_Surface *bg      = NULL;  // background
	SDL_Surface *screen  = NULL;  // screen/window

	int width			 = 1600;  // width (in pixels)
	int height			 = 1200;  // height
	int bpp 			 = 32;    // bits per pixel (color depth)

	int quit 			 = 0;
	int x  				 = 0;
	int y				 = 0;

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
	
	while (quit == 0)
	{
		apply_surface(0, 0, bg,  screen);
		apply_surface(x, y, img, screen);

		if (SDL_Flip(screen) == -1)
		{
			exit(3);
		}

		SDL_Delay(250);
		
//		x = x + 10;
//		y = y + 5;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quit = 1;
						break;
					
					case SDLK_UP:
						y = y - 10;
						break;
					
					case SDLK_DOWN:
						y = y + 10;
						break;

					case SDLK_LEFT:
						x = x - 10;
						break;
					case SDLK_RIGHT:
						x = x + 10;
						break;
					
					default:
						break;
				}
			}
			if (event.type == SDL_QUIT)
			{
				quit = 1;

			}	
		}
	}

	SDL_FreeSurface(img);
	SDL_FreeSurface(bg);

	SDL_Quit();

	return(0);
}	
