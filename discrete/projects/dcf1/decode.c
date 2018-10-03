#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// variables
	//
	FILE		  *in					 = NULL;
	FILE		  *out				     = NULL;
	char          *outName				 = NULL;
	char 		  *outPath				 = malloc(sizeof(char) * 64);
	unsigned char  header[12];
	unsigned long  bI					 = 0;
	unsigned long  bO					 = 0;
	int 		  *pattern				 = NULL;
	int 		   index				 = 0;
	int            index2				 = 0;
	int            count 				 = 0;
	int            EOF_FLAG              = 0;
	float          rate  				 = 0;
	
	//////////////////////////////////////////////////////////////////
	//
	// process command-line, no arguments get an error
	//
	if (argc							<  2)
	{
		fprintf(stderr, "ERROR: Not enough arguments\n");
		exit(1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// if given, open specified file for reading
	//
	else
	{
		in							     = fopen(argv[1], "r");
		if (in						    == NULL)
		{
			fprintf(stderr, "Error opening '%s' for reading\n", argv[1]);
			exit (1);
		}
	}

	for (index = 0; index < 12; index++)
	{
		header[index] = fgetc(in);
		bI++;
	}
	pattern = malloc(sizeof(int)  * header[10]);
	outName = malloc(sizeof(char) * header[11]);
	for (index = 0; index < header[11]; index++)
	{
		outName[index] = fgetc(in);
		bI++;
	}
	strcat(outPath, argv[2]);
	strcat(outPath, "/");
	strcat(outPath, outName);
	out      = fopen(outPath, "w");
	if (out == NULL)
	{
		fprintf(stderr, "Error opening '%s' for writing\n", outName);
		exit (1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// your dcfX RLE v2 decoding implementation
	//
	while (EOF_FLAG == 0)
	{
		count = fgetc(in);
		if (count == EOF)
		{
			break;
		}
		bI++;
		// stride is header[10]
		for (index = 0; index < header[10]; index++)
		{
			pattern[index] = fgetc(in);
			bI++;
			if (pattern[index] == EOF)
			{
				break;
			}
		}
		if (EOF_FLAG == 0)
		{
			for (index = 0; index < count; index++)
			{
				for (index2 = 0; index2 < header[10]; index2++)
				{
					if (pattern[index2] != EOF)
					{
						fputc(pattern[index2], out);
						bO++;
					}
					else
					{
						// I didnt have this else break statement and when I put it in
						// the stars aligned, 3/4 of the tests passed.

						// Confirmed I am God's chosen, divine intellect
						break;
					}
				}		
			}
		}
	}

	// INFORMATION
	fprintf(stdout, "    input filename: %s\n", argv[1]);
	fprintf(stdout, "output name length: %d bytes\n", (int)strlen(outName));
	fprintf(stdout, "   output filename: %s\n", outName);
	fprintf(stdout, "       header text: dcvX RLE v2\n");
	fprintf(stdout, "      stride value: %d bytes\n", header[10]);
	fprintf(stdout, "           read in: %d bytes\n", bI);
	fprintf(stdout, "  data written out: %ld bytes\n", bO);
	rate = ((float)bO / (float)bI) * 100;
	fprintf(stdout, "    inflation rate: %.02f", rate);
	fprintf(stdout, "%%\n");




	//////////////////////////////////////////////////////////////////
	//
	// close our open files
	//
	fclose(in);
	fclose(out);

	return(0);
}
