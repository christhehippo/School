#include "stuff.h"

int main()
{
	SDL_Event    event;
	
	SDL_Surface *img	 = NULL;  // image (to put on background)
	SDL_Surface *img2    = NULL;
	SDL_Surface *bg      = NULL;  // background
	SDL_Surface *screen  = NULL;  // screen/window

	int width			 = 1600;  // width (in pixels)
	int height			 = 1200;  // height
	int bpp 			 = 32;    // bits per pixel (color depth)

	int quit 			 = 0;
	int x  				 = 0;
	int y				 = 0;
	int x_move           = 10;
	int x_move_mod       = 1;
	int y_move           = 10;
	int y_move_mod       = 1;
	int speed 			 = 50;

	int x2  				 = 0;
	int y2				 = 0;
	int x_move2           = -10;
	int x_move_mod2       = 1;
	int y_move2           = -10;
	int y_move_mod2       = 1;


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

	img = load_image("dog2.png");
	img2 = load_image("cat.jpg");
	bg  = load_image("bg.jpg");
	

	while (quit == 0)
	{
		apply_surface(0, 0, bg,  screen);
		apply_surface(x, y, img, screen);
		apply_surface(x2, y2, img2, screen);

		if (SDL_Flip(screen) == -1)
		{
			exit(3);
		}

		SDL_Delay(speed);
		
		x = x + x_move * x_move_mod;
		y = y + y_move * y_move_mod;
		
		// no go below zero
		if (x_move_mod <= 0)
			x_move_mod = 1;
		else if (y_move_mod <= 0)
			y_move_mod = 1;

		if (x >= (bg -> w) - (img -> w))
			x_move = -10;
		else if (x <= 0)
			x_move = 10;
		else if (y >= (bg -> h) - (img -> h))
			y_move = -10;
		else if (y <= 0)
			y_move = 10;

		x2 = x2 + x_move2 * x_move_mod2;
		y2 = y2 + y_move2 * y_move_mod2;
		
		// no go below zero
		if (x_move_mod2 <= 0)
			x_move_mod2 = 1;
		else if (y_move_mod2 <= 0)
			y_move_mod2 = 1;

		if (x2 >= (bg -> w) - (img2 -> w))
			x_move2 = -10;
		else if (x2 <= 0)
			x_move2 = 10;
		else if (y2 >= (bg -> h) - (img2 -> h))
			y_move2 = -10;
		else if (y2 <= 0)
			y_move2 = 10;
		


		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = 1;

			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quit = 1;
						break;

					case SDLK_UP:
						y_move_mod++;
						y_move_mod2++;
						break;

					case SDLK_DOWN:
						y_move_mod--;
						y_move_mod2--;	
						break;

					case SDLK_LEFT:
						x_move_mod--;
						x_move_mod2--;
						break;

					case SDLK_RIGHT:
						x_move_mod++;
						x_move_mod2++;
						break;

					case SDLK_SPACE:
						x_move_mod = 1;
						y_move_mod = 1;
						x_move_mod2 = 1;
						y_move_mod2 = 1;
						break;

					case SDLK_q:
						quit = 1;
						break;

					default:
						break;
				}
			}
		}
	}

	SDL_FreeSurface(img);
	SDL_FreeSurface(bg);

	SDL_Quit();

	return(0);
}	
