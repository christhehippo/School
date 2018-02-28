////////////////////////////////////////
//       psd0
// Christian Cattell
// compile: gcc -o psd0 psd0.c -Wall -std=c99
//   Yes I know I could have made more functions to save typing,
//   2d arrays are weird though.

#include <stdio.h>
#include <stdlib.h>

void goToLine (char whatLine,  FILE *fp);
void goToComma(char whatComma, FILE *fp);

int main (int argc, char **argv)
{
////////////////Set up some stuff////////////////////////	
	FILE *fp;
	fp = fopen(argv[1], "r");
	char filePos;
	int lineCount = 0;

	goToLine(1, fp); // go past label line

	while (filePos != EOF) // get a value for the number of lines we have
	{
		filePos = fgetc(fp);
		if (filePos == 10)
		{
			lineCount++;
		}
	}
	
	goToLine(1, fp);
////////////////////Dates//////////////////////////////////
	
	char dates[lineCount][11]; // dates horizontal, vertical is for align
	int x = 0; // These refer to 2d array axii
	int y = 0;
	char y2= 1;
	for (y = 0; y < lineCount; y++) // populate date data
	{
		for (x = 0; x < 11; x++)
		{
			dates[y][x] = filePos; // I got lost messing with this
			filePos = fgetc(fp);   //  but it works now as far as i can tell
		}
		y2++;	
		goToLine(y2, fp);
		
	}

///////Open/////////////////////////////////////////////////////

	char open[lineCount][6]; // open horizontal, vertical is for align
	x = 0; // These refer to 2d array axii
	y = 0;
	y2 = 2;
	goToLine (1, fp);
	goToComma(1, fp);
	filePos = fgetc(fp);

	for (y = 0; y < lineCount; y++) // populate data
	{
		for (x = 0; x < 6; x++)
		{
			open[y][x] = filePos;
			if (open[y][x] == 44)
			{
				open[y][x] = 48;
			}
			filePos = fgetc(fp);   
		}
		
		goToLine((y+1), fp);
		goToComma(1, fp);
		filePos = fgetc(fp);
	}

///////High/////////////////////////////////////////////////////

	char high[lineCount][6]; // open horizontal, vertical is for align
	x = 0; // These refer to 2d array axii
	y = 0;
	goToLine (1, fp);
	goToComma(2, fp);
	filePos = fgetc(fp);

	for (y = 0; y < lineCount; y++) // populate data
	{
		for (x = 0; x < 6; x++)
		{
			high[y][x] = filePos;
			if (high[y][x] == 44)
			{
				high[y][x] = 48;
			}
			filePos = fgetc(fp);   
		}
		
		goToLine((y+1), fp);
		goToComma(2, fp);
		filePos = fgetc(fp);
	}

////////////Low/////////////////////////////////////////////////////	
	char low[lineCount][6]; // open horizontal, vertical is for align
	x = 0; // These refer to 2d array axii
	y = 0;
	goToLine (1, fp);
	goToComma(3, fp);
	filePos = fgetc(fp);

	for (y = 0; y < lineCount; y++) // populate data
	{
		for (x = 0; x < 6; x++)
		{
			low[y][x] = filePos;
			if (low[y][x] == 44)
			{
				low[y][x] = 48;
			}
			filePos = fgetc(fp);   
		}
		
		goToLine((y+1), fp);
		goToComma(3, fp);
		filePos = fgetc(fp);
	}

//////////////Close////////////////////////////////////////////////
	char close[lineCount][6]; // open horizontal, vertical is for align
	x = 0; // These refer to 2d array axii
	y = 0;
	goToLine (1, fp);
	goToComma(4, fp);
	filePos = fgetc(fp);

	for (y = 0; y < lineCount; y++) // populate data
	{
		for (x = 0; x < 6; x++)
		{
			close[y][x] = filePos;
			if (close[y][x] == 44)
			{
				close[y][x] = 48;
			}
			filePos = fgetc(fp);   
		}
		
		goToLine((y+1), fp);
		goToComma(4, fp);
		filePos = fgetc(fp);
	}

///////////////////////////////////Adjusted cl/////////////////////
char adj[lineCount][6]; // open horizontal, vertical is for align
	x = 0; // These refer to 2d array axii
	y = 0;
	goToLine (1, fp);
	goToComma(5, fp);
	filePos = fgetc(fp);

	for (y = 0; y < lineCount; y++) // populate data
	{
		for (x = 0; x < 6; x++)
		{
			adj[y][x] = filePos;
			if (adj[y][x] == 44)
			{
				adj[y][x] = 48;
			}
			filePos = fgetc(fp);   
		}
		
		goToLine((y+1), fp);
		goToComma(5, fp);
		filePos = fgetc(fp);
	}

////////////////////////Vol/////////////////////////////////
char vol[lineCount][7]; // open horizontal, vertical is for align
	x = 0; // These refer to 2d array axii
	y = 0;
	goToLine (1, fp);
	goToComma(6, fp);
	filePos = fgetc(fp);

	for (y = 0; y < lineCount; y++) // populate data
	{
		for (x = 0; x < 7; x++)
		{
			vol[y][x] = filePos;
			if (vol[y][x] == EOF || vol[y][x] == 10)
			{
				vol[y][x] = 9;
			}
			filePos = fgetc(fp);   
		}
		
		goToLine((y+1), fp);
		goToComma(6, fp);
		filePos = fgetc(fp);
	}

////////////////////////////Printing///////////////////////
	fprintf(stdout, "Date         Open     High     Low      Close    AdjCl    Volume\n");
	fprintf(stdout, "-----------------------------------------------------------------\n");
	int line = 0;
	for (line = 0; line < lineCount; line++)
	{
		// Date
		for (x = 1; x < 11; x++)
		{
			fprintf(stdout, "%c", dates[line][x]);
		}
		fprintf(stdout, "   ");
		// Open
		for (x = 0; x < 6; x++)
		{
			fprintf(stdout, "%c", open[line][x]);
		}
		fprintf(stdout, "   ");
		// High
		for (x = 0; x < 6; x++)
		{
			fprintf(stdout, "%c", high[line][x]);
		}
		fprintf(stdout, "   ");
		// Low
		for (x = 0; x < 6; x++)
		{
			fprintf(stdout, "%c", low[line][x]);
		}
		fprintf(stdout, "   ");
		// Close
		for (x = 0; x < 6; x++)
		{
			fprintf(stdout, "%c", close[line][x]);
		}

		fprintf(stdout, "   ");
		// Adj Close
		for (x = 0; x < 6; x++)
		{
			fprintf(stdout, "%c", adj[line][x]);
		}
		fprintf(stdout, "   ");
		for (x = 0; x < 7; x++)
		{
			fprintf(stdout, "%c", vol[line][x]);
		}


		printf("\n");
	}





	fclose(fp);
	return (0);
}

// Function that does p much what its name says
void goToLine(char whatLine, FILE *fp)
{
	// LINE 1 WILL BE LINE BELOW DATE,...
	rewind(fp);
	char filePos;
	int lineCount = 0;
	while (1)
	{
		filePos = fgetc(fp); // Want to ditch the date, open, etc
		if (filePos == 10)
		{
			lineCount++;              
			if (lineCount == whatLine)
			{
				
				break;		// We reached the point we want to be at
			}
		}
	}

}

void goToComma(char whatComma, FILE *fp)
{
	char filePos;
	char commaCount = 0;
	while (commaCount != whatComma)
	{
		filePos = fgetc(fp);
		if (filePos == 44)
		{	
			commaCount++;
		}
	}
}


