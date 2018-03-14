////////////////////////////////////////////////////////
//				psd1.c
//      Christian Cattell
// 
// This is using the raw stock data, not the data that psd0 made
// As far as I can tell, the seconds day listed never shows up,
// no idea why but maybe ill find it on psd2.

#include <stdio.h>
#include <stdlib.h>
#include <gd.h>
#include <sys/stat.h>
#include <string.h>
#include <gdfontt.h>
#include <gdfonts.h>
#include <gdfontmb.h>
#include <gdfontl.h>
#include <gdfontg.h>
#include <math.h>


// colors
#define BLACK 		0
#define BLUE		1
#define GREEN		2
#define RED 		3	
#define WHITE		4

// Creates a single candle based on passed parameters
void candle(FILE*, int, gdImagePtr, int*, char *); 
// Counts the lines of the file
int lineCount(FILE *);

int main (int argc, char **argv)
{
///////////////VARS/////////////////////////////////////////
	char *outfile 	= NULL; 		// Name of output file
	FILE *out 	  	= NULL; 		// Output file pointer
	FILE *stockData = NULL; 		// Stock data
	gdImagePtr img;					// Thing gd uses
	int color[5]; 					// Color array
	int width = 1921, height = 1081;// Dimensions
//	char line[150];					// Array to store a line
	int lineNum;					// Line count
/*	// Float variables -- Stock information
	float open;
	float high;
	float low;
	float close;*/
////////////////////////////////////////////////////////////


	// Allocating outfile
	outfile = (char *) malloc(sizeof(char) * 64);
	sprintf(outfile, "/home/%s/public_html/psd1.png", getenv("USER"));
	fprintf(stdout, "View at: https://lab46.g7n.org/~%s/psd1.png\n", getenv("USER"));	

	// Open the stock data
	stockData = fopen(argv[1], "r");

	// Get line count, max 15
	lineNum = lineCount(stockData);

	// Create the image
	img = gdImageCreate(width, height);
	
	// Colors array populate
	color[BLACK] = gdImageColorAllocate(img, 0x00, 0x00, 0x00);
	color[BLUE]  = gdImageColorAllocate(img, 0x00, 0x00, 0xFF);
	color[GREEN] = gdImageColorAllocate(img, 0x00, 0xFF, 0x00);
	color[RED]   = gdImageColorAllocate(img, 0xFF, 0x00, 0x00);
	color[WHITE] = gdImageColorAllocate(img, 0xFF, 0xFF, 0xFF);

	// Fill background with white
	gdImageFilledRectangle(img, 0, 0, width-1, height-1, color[BLACK]);
	
	// Make axis
	gdImageFilledRectangle(img, 100, 50, 110, 900, color[WHITE]);
	gdImageFilledRectangle(img, 110, 890, 1870, 900, color[WHITE]);

	// Create candles
	candle(stockData, lineNum, img, color, argv[1]);


////////////////////////////////////////////////////////////

	// Close things
	out = fopen(outfile, "wb");
	if (out == NULL)
	{
		fprintf(stderr, "Error opening '%s'\n", outfile);
		return (1);
	}
	chmod(outfile, 0644);
	gdImagePngEx(img, out, -1);
	fclose(out);
	fclose(stockData);
	gdImageDestroy(img);
	

	return (0);
}


void candle(FILE* stockData, int lineNum, gdImagePtr img, int *color, char *arg)
{
	char line[150];
	float open;
	float firstOpen;
	char  foString[9];
	float high;
	float low;
	float close;
	int lineCount  = 0;
	int commaCount = 0;
	int i = 1;
	int n = 0;
	int x1, x2, y1, y2;
	char date[20];
	char delim[2] = ",";
	char *token;

	
	// Graph title
	gdImageString(img, gdFontGiant, 850, 50, arg, color[WHITE]); 
		

	// Candles	
	for (i = 1; i < lineNum - 1; i++)
	{

/////////GETTING VALUES////////////////////////////////////
		while (1) // GOTO line
		{
			if (fgetc(stockData) == '\n')
				lineCount++;
		
			if (lineCount == i)
				break;
		}

		// Get the date
		fgets(line, 150, stockData);
		for (n = 0; n < 10; n++)
			date[n] = line[n];
		
		lineCount = 0;
		rewind(stockData);

		// Reset
		lineCount  = 0;
		commaCount = 0;
		rewind(stockData);
		while (1) // GOTO line
		{	
			if (fgetc(stockData) == '\n')
				lineCount++;
		
			if (lineCount == i)
				break;
		}

		// GETTING OPEN	
		while (1) // Skip to first comma
		{
			if (fgetc(stockData) == ',')
				break;
		}

		// Write line  to line[150] array
		fgets(line, 150, stockData);

		open = strtof(line, NULL);
		if (i == 1)
		{
			firstOpen = open;
			for (n = 0; n < 7; n++)
				foString[n] = line[n]; // Printing the middle number of left side 
			gdImageString(img, gdFontLarge, 5, 475, foString, color[WHITE]);
		}
		printf("open: %f  ", open);
		// OPEN OBTAINED

		// Reset
		lineCount  = 0;
		commaCount = 0;
		rewind(stockData);
		while (1) // GOTO line
		{	
			if (fgetc(stockData) == '\n')
				lineCount++;
		
			if (lineCount == i)
				break;
		}

		// GETTING HIGH -- nice
		while (1) // Skip to second comma
		{
			if (fgetc(stockData) == ',')
				commaCount++;
		
			if (commaCount == 2)
				break;
		}
	
		fgets(line, 150, stockData);
		high = strtof(line, NULL);
		printf("high: %f  ", high);
		// HIGH OBTAINED
		
		// Reset
		lineCount  = 0;
		commaCount = 0;
		rewind(stockData);
		while (1) // GOTO line
		{	
			if (fgetc(stockData) == '\n')
				lineCount++;
		
			if (lineCount == i)
				break;
		}

		// GETTING LOW
		while (1) // Skip to third comma
		{
			if (fgetc(stockData) == ',')
				commaCount++;
		
			if (commaCount == 3)
				break;
		}
	
		fgets(line, 150, stockData);
		low = strtof(line, NULL);
		printf("low: %f  ", low);
		// LOW OBTAINED

		// Reset
		lineCount  = 0;
		commaCount = 0;
		rewind(stockData);
		while (1) // GOTO line
		{	
			if (fgetc(stockData) == '\n')
				lineCount++;
		
			if (lineCount == i)
				break;
		}

		// GETTING CLOSE
		while (1) // Skip to fourth comma
		{
			if (fgetc(stockData) == ',')
				commaCount++;
		
			if (commaCount == 4)
				break;
		}
	
		fgets(line, 150, stockData);
		close = strtof(line, NULL);
		printf("close: %f  ", close);

		printf("\n");

/////////////////////CREATE CANDLESTICK////////////////////	
		
		// First off, make the high-low line
		// A ton of math that calculates % change and bases coordinates on that - MAX 10%
		x1 = 100 + (i * (1770 / lineNum));
		x2 = 100 + (i * (1770 / lineNum));
		y1 = 475 - ((((high - firstOpen) * 100) / firstOpen) * 94);  // CURRENTLY TESTING 5% MAX
		y2 = 475 + ((((firstOpen - low)  * 100) / firstOpen) * 94);
//		printf("x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
		
		gdImageLine(img, x1, y1, x2, y2, color[WHITE]);

		// Do vertical date text
		gdImageStringUp(img, gdFontGiant, x1, 1000, date, color[WHITE]);

		// Next make some boxes
		y1 = 0; y2 = 0;
		// Green box
		if (open < close)
		{
			x1 = x1 - 25;
			x2 = x2 + 25;
			// I use the first open value as a baseline for axis placement
			if (close < firstOpen)
				y1 = 475 + ((100 - (close * 100) / firstOpen) * 94);
			else
				y1 = 475 - ((((close * 100) / firstOpen) - 100) * 94);
			// Do y2 now
			if (open < firstOpen)
				y2 = 475 + ((100 - (open * 100) / firstOpen) * 94);
			else
				y2 = 475 - ((((open * 100) / firstOpen) - 100) * 94);
			
//			printf("x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
			
			gdImageFilledRectangle(img, x1, y1, x2, y2, color[GREEN]); 
		}
		// Red box
		else
		{
			x1 = x1 - 25;
			x2 = x2 + 25;
			// I use the first open value as a baseline for axis placement
			if (close < firstOpen)
				y2 = 475 + ((100 - (close * 100) / firstOpen) * 94);
			else
				y2 = 475 - ((((close * 100) / firstOpen) - 100) * 94);
			// Do y2 now
			if (open < firstOpen)
				y1 = 475 + ((100 - (open * 100) / firstOpen) * 94);
			else
				y1 = 475 - ((((open * 100) / firstOpen) - 100) * 94);
			
//			printf("x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
			
			gdImageFilledRectangle(img, x1, y1, x2, y2, color[RED]); 
		}
	

	}
	// Doing other left side of graph things
	// not very precise, not sure why but text doesnt go exactly where I want
	gdImageString(img, gdFontLarge, 5, 475-(84*1), "+1%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475+(84*1), "-1%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475-(84*2), "+2%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475+(84*2), "-2%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475-(84*3), "+3%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475+(84*3), "-3%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475-(84*4), "+4%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475+(84*4), "-4%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475-(84*5), "+5%", color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 475+(84*5), "-5%", color[WHITE]);

}

int lineCount(FILE *stockData)
{
	int lc = 0;
	int c;
	while ((c = fgetc(stockData)) != EOF)
	{
		if (c == '\n')
			lc++;
	}
	
	rewind(stockData);
	return (lc);

}
