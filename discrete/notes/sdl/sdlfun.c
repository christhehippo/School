#include <stdlib.h>
#include <SDL/SDL.h>

int main()
{
	SDL_Surface *image   = NULL;
	SDL_Surface *screen  = NULL;

	SDL_Surface *image2   = NULL;
	SDL_Surface *screen2  = NULL;

	SDL_Init(SDL_INIT_EVERYTHING); // turn it on, all of it
	screen  = SDL_SetVideoMode(490, 462, 32, SDL_SWSURFACE);

	int i = 0;
	for (i = 0; i < 1000; i++)
	{


		image = SDL_LoadBMP("bmp.bmp");
		image2 = SDL_LoadBMP("bmp2.bmp");

		SDL_BlitSurface(image, NULL, screen, NULL);


		SDL_Flip(screen);

		SDL_Delay(100);


		SDL_FreeSurface(image);

		SDL_BlitSurface(image2, NULL, screen2, NULL);


		SDL_Flip(screen2);

		SDL_Delay(100);


		SDL_FreeSurface(image2);

		


	}

	SDL_Quit();
	

	return (0);
}

