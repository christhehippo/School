/* 
 cos0.c   - skeleton code to use the GD graphics library
 *                        to create an image (circle of squares).
 *
 * To compile: type 'make' to compile the program
 *         or: gcc --std=c99 -Wall -o cos0 cos0.c -lgd
 * To execute: ./cos0 ARGS
 *
 * Documentation:  http://www.boutell.com/gd/manual2.0.33.html
 *                 https://libgd.github.io/manuals/2.1.1/index/Functions.html
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <gd.h>
#include <math.h>

// color values
#define BLACK       0
#define BLUE        1
#define GREEN       2
#define RED         3
#define WHITE       4
#define YEE  		5

int main(int argc, char **argv)
{
	char               *outfile = NULL;    							 // name out of the output file
    FILE               *out     = NULL;    						 	 // output file pointer
    gdImagePtr          img;        	   							 // GD Image Construct
    unsigned int        color[5];          							 // color array
    unsigned short int  wide, high, radius, xCenter, yCenter;        // image attributes
 
	// Checking to see if the user wants the default name of cos0.png or if they want to name
	// the file themselves. .png is added to the end of the filename.
	if(argc == 7)
	{
		char filename[16];
		strcpy(filename, argv[6]);
		outfile = *(argv+6);
		fprintf(stderr, "Using '%s' as output filename\n", outfile);
		sprintf(outfile, "/home/%s/public_html/%s.png", getenv("USER"), filename);	
	}
	else if(argc == 6)
	{
		outfile = (char *) malloc (sizeof (char) * 64);
		fprintf(stderr, "Using 'cos0.png' as output filename\n");
		sprintf(outfile, "/home/%s/public_html/cos0.png", getenv("USER"));
	}
	else
	{
		fprintf(stdout, "ERROR: Too few arguments.\n");
		return (1);
	}
	
	// convert pointer array to workable value
	wide    = strtol(argv[1], NULL, 10);
	high    = strtol(argv[2], NULL, 10);
	radius  = strtol(argv[3], NULL, 10);
	xCenter = strtol(argv[4], NULL, 10);
	yCenter = strtol(argv[5], NULL, 10);
	
	// If the user puts a 0 for either of the values of the midpoint, it will
	// automatically replace the 0 with the mid point in regards to x or y.
	if (xCenter == 0)
	{
		xCenter = ((wide-1)/2);
	}
	if (yCenter == 0)
	{
		yCenter = ((high-1)/2);
	}

	//Some errors
	if(wide == high)
	{
		fprintf(stderr, "ERROR: Image can't be a square.\n");
		return (2);
	}
	if(wide < 600 || wide > 1024)
	{
		fprintf(stderr, "ERROR: min size is 600 x 800, max size is 1024 x 1280\n");
		return (3);
	}
	if(high < 800 || wide > 1280)
	{
		fprintf(stderr, "ERROR: min size is 600 x 800, max size is 1024 x 1280\n");
		return (3);
	}
	//Create image
	img = gdImageCreate(wide, high);
	
	//The names of these colors are a bunch of lies 	
	color[BLACK] = gdImageColorAllocate(img, 0x00, 0x00, 0x00);
    color[BLUE]  = gdImageColorAllocate(img, 0xEF, 0x2F, 0x00);
    color[GREEN] = gdImageColorAllocate(img, 0xEF, 0x5F, 0x00);
    color[RED]   = gdImageColorAllocate(img, 0xEF, 0x00, 0x00);
    color[WHITE] = gdImageColorAllocate(img, 0xFF, 0xFF, 0xFF);
	color[YEE]   = gdImageColorAllocate(img, 0xEF, 0x6F, 0x00);

	//Paint background black
	gdImageFilledRectangle(img, 0, 0, wide-1, high-1, color[BLACK]);
	//Paint outline	
	gdImageFilledRectangle(img, 0, 0, wide-1, 1, color[WHITE]);
	gdImageFilledRectangle(img, 0, 0, 1, high-1, color[WHITE]);
	gdImageFilledRectangle(img, 0, high-2, wide-1, high-1, color[WHITE]);
	gdImageFilledRectangle(img, wide-2, 0, wide-1, high-1, color[WHITE]);
	//Circle stuff
//	gdImageFilledRectangle(img, xCenter, yCenter, xCenter-12, yCenter-12, color[RED]); 
	
	//	The process here was to take the value for y given point x +/- an interval of 12 (xCenter + radius)
	//	using the math.h lib. x^2 + y^2 = radius^2 , y = sqrt(radius^2 - x^2). Then 
	//  offset the points with the center values in order to deal with not starting at 
	//  point (0,0). Then I repeated the process, but used y in x's place. This filled 
	//  the holes in the circle since they aren't very linear. The use of 4 loops wasn't 
	// 	needed, but the number of things that could go wrong with this (and did go wrong)
	//  was pretty high. Isolating things helps isolate problems.
	
	unsigned short int xRadius, yRadius, diam;
	xRadius = xCenter + radius;
	yRadius = yCenter + radius;
	diam = radius * 2;

	int i, xQ4, yQ4;
	for (i = 0; i <= diam; i = i + 12)
	{
		xQ4 = (xRadius - i);
		yQ4 = yCenter + (sqrt((pow(radius, 2) - pow((xQ4 - xCenter), 2))));
//		fprintf(stderr, "(Q4 %d, %d)\n", xQ4, yQ4);
		gdImageFilledRectangle(img, xQ4, yQ4, xQ4-12 , yQ4+12 , color[RED]);
		
	}	

	int j, xQ1, yQ1;
	for (j = 0; j <= diam; j = j + 12)
	{
		xQ1 = (xRadius - j);
		yQ1= yCenter - (sqrt((pow(radius, 2) - pow((xQ1 - xCenter), 2))));
//		fprintf(stderr, "(%d, %d)\n", xQ1, yQ1);
		gdImageFilledRectangle(img, xQ1, yQ1, xQ1-12 , yQ1+12 , color[GREEN]);
		
	}
	
	int k, xQ2, yQ2;
	for (k = 0; k <= diam; k = k + 12)
	{
		yQ2 = (yRadius - k);
		xQ2 = xCenter + (sqrt((pow(radius, 2) - pow((yQ2 - yCenter), 2))));
//		fprintf(stderr, "(Q2 %d, %d)\n", xQ2, yQ2);
		gdImageFilledRectangle(img, xQ2, yQ2, xQ2-12 , yQ2+12 , color[BLUE]);
		
	}	

	int l, xQ3, yQ3;
	for (l = 0; l <= diam; l = l + 12)
	{
		yQ3 = (yRadius - l);
		xQ3= xCenter - (sqrt((pow(radius, 2) - pow((yQ3 - yCenter), 2))));
//		fprintf(stderr, "(%d, %d)\n", xQ3, yQ3);
		gdImageFilledRectangle(img, xQ3, yQ3, xQ3-12 , yQ3+12 , color[YEE]);
		
	}
	//closing stuff
	out     = fopen(outfile, "wb");
    if(out == NULL)
	{
		fprintf(stderr, "Error opening '%s'\n", outfile);
		return (4);
	}
	
	chmod (outfile, 0644);

	gdImagePngEx(img, out, -1);

	fclose(out);
	gdImageDestroy(img);

//	fprintf(stdout, "wide: %d, high: %d, radius: %d, xCenter: %d, yCenter: %d\n", wide, high, radius, xCenter, yCenter);
	
	return(0);
}
