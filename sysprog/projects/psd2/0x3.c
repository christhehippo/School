// eoce 0x3 compile gcc --std=c99 -Wall -o 0x3 0x3.c -lgd -lm

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <gd.h>
#include <math.h>
#include <string.h>

#define RED   0
#define WHITE 1
#define BLUE  2

// Function to make a stripe
void stripe(char i, int width, gdImagePtr img, unsigned int *color);
// Function to convert degrees to radians
double degToRad(float degree);
// Function to draw and fill a star
void star(int width, int height, float degree, gdImagePtr img, unsigned int *color);

int main()
{
	char *outfile = NULL;   // Name of output file
	FILE *out     = NULL;   // Pointer to output file
	gdImagePtr img;         // GD Image Construct
	unsigned int color[3];  // Colors
	
	int width = 1920, height = 1010;

	// Allocate for outfile, then write to outfile
	outfile = (char *) malloc (sizeof (char) * 64);
	fprintf(stderr, "\nUsing '0x3.png' as output filename\n");
	fprintf(stderr, "\nVIEW AT: https://lab46.g7n.org/~ccattell/0x3.png\n\n");
	sprintf(outfile, "/home/%s/public_html/0x3.png", getenv("USER"));
	
	// Create base image
	img = gdImageCreate(width, height); // Same size as provided image

	// Color values
	color[RED]   = gdImageColorAllocate(img, 0xFF, 0x00, 0x00);
	color[WHITE] = gdImageColorAllocate(img, 0xFF, 0xFF, 0xFF);
	color[BLUE]  = gdImageColorAllocate(img, 0x00, 0x60, 0xFF);

	// Make bg white
	gdImageFilledRectangle(img, 0, 0, width-1, height-1, color[WHITE]);

	// Make red stripes
	char stripeLoop = 0;
	for (stripeLoop = 0; stripeLoop < 8; stripeLoop++)
		stripe(stripeLoop, width, img, &color[0]);

	// Make blue sqaure piece
	gdImageFilledRectangle(img, 0, 0, width/3, height/2, color[BLUE]);

	// Make stars
	char starLoop = 1;
	for (starLoop = 1; starLoop < 14; starLoop++)
		star(width, height, starLoop*28, img, &color[0]); // *28 because 360/13 = about 28

	//Closing stuff
	out = fopen(outfile, "wb");
	if(out == NULL)
	{
		fprintf(stderr, "Error opening '%s'\n", outfile);
		return(1);
	}
	chmod (outfile, 0644);
	gdImagePngEx(img, out, -1);
	fclose(out);
	gdImageDestroy(img);


	return(0);
}

// Function to create stripe at point i * 155
void stripe(char i, int width, gdImagePtr img, unsigned int *color)
{
	gdImageFilledRectangle(img, 0, (i*155), width-1, ((i*155)+80), color[RED]);
}

// Converts degrees to radians for use of cos/sin functions
double degToRad(float degree)
{
	// radians = degrees * (pi / 180)
	double radian = (degree * M_PI) / 180;
	return(radian);
}

void star(int width, int height, float degree, gdImagePtr img, unsigned int *color)
{
	// Find midpoint of circle/star (same thing kind of)
	int x = (320 + (180 * cos(degToRad(degree))));
	int y = (227 + (180 * sin(degToRad(degree))));
	
	// Draw lines of star
	gdImageLine(img, x-12, y+24, x, y-24, color[WHITE]);
	gdImageLine(img, x, y-24, x+12, y+24, color[WHITE]);
	gdImageLine(img, x+12, y+24, x-24, y-8, color[WHITE]); 
	gdImageLine(img, x-24, y-8, x+24, y-8, color[WHITE]);
	gdImageLine(img, x+24, y-8, x-12, y+24, color[WHITE]);

	// Fill in star
	gdImageFillToBorder(img, x, y, color[WHITE], color[WHITE]);
	gdImageFillToBorder(img, x, y-12, color[WHITE], color[WHITE]);
	gdImageFillToBorder(img, x-12, y, color[WHITE], color[WHITE]);
	gdImageFillToBorder(img, x+12, y, color[WHITE], color[WHITE]);
	gdImageFillToBorder(img, x-7, y+10, color[WHITE], color[WHITE]);
	gdImageFillToBorder(img, x+7, y+10, color[WHITE], color[WHITE]);
}

