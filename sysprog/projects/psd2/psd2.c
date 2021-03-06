////////////////////////////////////////////////////////
//				psd2.c
//      Christian Cattell
// 
//	  THE SAME BUT DIFFERENT
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
	int width = 1921, height = 1481;// Dimensions
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
	sprintf(outfile, "/home/%s/public_html/psd2.png", getenv("USER"));
	fprintf(stdout, "View at: https://lab46.g7n.org/~%s/psd2.png\n", getenv("USER"));	

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

	// Make volume axis
	gdImageFilledRectangle(img, 100, 1011, 110, 1431, color[WHITE]);
	gdImageFilledRectangle(img, 110, 1011, 1870, 1021, color[WHITE]);

	// Create candles
	candle(stockData, lineNum, img, color, argv[1]);
	////////////////////////////////////////////////////
	/*
	I meant to do this in seperate functions but it kind of worked out better
	having everything together. Poor planning by me but it works.
	*/
	///////////////////////////////////////////////////

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
	char  foString[10] = {0};
	char  fvString[10] = {0};
	float high;
	float low;
	float close;
	long int volume;
	long int firstVolume;
	int lineCount  = 0;
	int commaCount = 0;
	int i = 1;
	int n = 0;
	int a = 2;
	int x1, x2, y1, y2;
	char date[20] = {0};
	char delim[2] = ",";
	char *token;

	int perc = 47;
	if (lineNum > 100)	
		perc = 23;
	// Graph title
	gdImageString(img, gdFontGiant, 850, 50, arg, color[WHITE]); 
	gdImageString(img, gdFontGiant, 790, 100, "Candles Showing: Open, High, Low, and Close", color[WHITE]); 
	

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

		// GETTING VOLUME
		while (1) // Skip to sixth comma
		{
			if (fgetc(stockData) == ',')
				commaCount++;
		
			if (commaCount == 6)
				break;
		}
		fgets(line, 150, stockData);
		volume = strtol(line, NULL, 10);
		if (i == 1)
		{
			firstVolume = volume;
			sprintf(fvString, "%lu", volume);	
			gdImageString(img, gdFontLarge, 5, 1221, fvString, color[WHITE]);


		}
		printf("volume: %ld ", volume);

		printf("\n");

/////////////////////CREATE CANDLESTICK////////////////////	
		
		// First off, make the high-low line
		// A ton of math that calculates % change and bases coordinates on that - MAX 10%
		x1 = 100 + (i * (1770 / lineNum));
		x2 = 100 + (i * (1770 / lineNum));
		y1 = 475 - ((((high - firstOpen) * 100) / firstOpen) * perc);
		y2 = 475 + ((((firstOpen - low)  * 100) / firstOpen) * perc);
//		printf("x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
		
		gdImageLine(img, x1, y1, x2, y2, color[WHITE]);

		// Do vertical date text
		
		if (lineNum < 50)
		{
			gdImageStringUp(img, gdFontGiant, x1, 1000, date, color[WHITE]);
		}
		else if (lineNum < 100)
		{
			if ((a % 2) == 0)
				gdImageStringUp(img, gdFontGiant, x1, 1000, date, color[WHITE]);
			a++;
				
		}
		else 
		{
			if ((a % 4) == 0)
				gdImageStringUp(img, gdFontGiant, x1, 1000, date, color[WHITE]);
			a++;
				
		}
		
		// Next make some boxes
		y1 = 0; y2 = 0;
		// Green box
		if (open < close)
		{
			if (lineNum < 31)
			{
				x1 = x1 - 20;
				x2 = x2 + 20;
			}
			else if (lineNum < 61)
			{
				x1 = x1 - 15;
				x2 = x2 + 15;
			}
			else if (lineNum < 100)
			{
				x1 = x1 - 8;
				x2 = x1 + 8;
			}
			else if (lineNum < 150)
			{
				x1 = x1 - 5;
				x2 = x2 + 5;
			}
			else
			{
				x1 = x1 - 2;
				x1 = x1 + 2;
			}


			// I use the first open value as a baseline for axis placement
			if (close < firstOpen)
				y1 = 475 + ((100 - (close * 100) / firstOpen) * perc);
			else
				y1 = 475 - ((((close * 100) / firstOpen) - 100) * perc);
			// Do y2 now
			if (open < firstOpen)
				y2 = 475 + ((100 - (open * 100) / firstOpen) * perc);
			else
				y2 = 475 - ((((open * 100) / firstOpen) - 100) * perc);
			
//			printf("x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
			
			gdImageFilledRectangle(img, x1, y1, x2, y2, color[GREEN]); 
		}
		// Red box
		else
		{
			if (lineNum < 31)
			{
				x1 = x1 - 20;
				x2 = x2 + 20;
			}
			else if (lineNum < 61)
			{
				x1 = x1 - 15;
				x2 = x2 + 15;
			}
			else if (lineNum < 100)
			{
				x1 = x1 - 8;
				x2 = x1 + 8;
			}
			else if (lineNum < 150)
			{
				x1 = x1 - 5;
				x2 = x2 + 5;
			}
			else
			{
				x1 = x1 - 2;
				x1 = x1 + 2;
			}
			
			// I use the first open value as a baseline for axis placement
			if (close < firstOpen)
				y2 = 475 + ((100 - (close * 100) / firstOpen) * perc);
			else
				y2 = 475 - ((((close * 100) / firstOpen) - 100) * perc);
			// Do y2 now
			if (open < firstOpen)
				y1 = 475 + ((100 - (open * 100) / firstOpen) * perc);
			else
				y1 = 475 - ((((open * 100) / firstOpen) - 100) * perc);
			
//			printf("x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
			
			gdImageFilledRectangle(img, x1, y1, x2, y2, color[RED]); 
		}
	
	// Volume stuff goes here
		x1 = 100 + (i * (1770 / lineNum));
		
		if (volume < firstVolume) // So i think this works out to 1% per pixel
			y1 = 1221 + ((100 - (volume * 100) / firstVolume));
		else
			y1 = 1221 - ((((volume * 100) / firstVolume) - 100));
		
		gdImageFilledRectangle(img, (x1 - (perc / 10)), (y1 - (perc / 10)), (x1 + (perc / 10)), 1440, color[BLUE]);



	}
	




	// Doing other left side of graph things
	// not very precise, not sure why but text doesnt go exactly where I want
	if (perc == 47)
	{
		gdImageString(img, gdFontLarge, 5, 475-(84*1), "+2%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*1), "-2%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*2), "+4%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*2), "-4%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*3), "+6%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*3), "-6%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*4), "+8%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*4), "-8%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*5), "+10%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*5), "-10%", color[WHITE]);
	}
	else 
	{
		gdImageString(img, gdFontLarge, 5, 475-(84*1), "+4%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*1), "-4%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*2), "+8%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*2), "-8%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*3), "+12%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*3), "-12%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*4), "+16%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*4), "-16%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475-(84*5), "+20%", color[WHITE]);
		gdImageString(img, gdFontLarge, 5, 475+(84*5), "-20%", color[WHITE]);
	}

	gdImageString(img, gdFontLarge, 5, 1221-25, "+25%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221-50, "+50%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221-75, "+75%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221-100, "+100%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221+25, "+25%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221+50, "+50%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221+75, "+75%",color[WHITE]);
	gdImageString(img, gdFontLarge, 5, 1221+100, "+100%",color[WHITE]);


		
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
