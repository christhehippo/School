#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Variable declarations
	//
	FILE *in						   = NULL;
	FILE *out						   = NULL;
	char *outpath					   = malloc(sizeof(char) * 64);
	char *base	 					   = NULL;
	int  *pattern					   = NULL;
	int  *patternOld                   = NULL;
	int   stride 					   = 0;
	int   index 					   = 0;
	int   count						   = 0;
	unsigned long   bI 				   = 0;
	unsigned long   bO				   = 0;
	int   EOF_FLAG					   = 0;
	int   DIF_FLAG					   = 0;
	int   COUNT_FLAG				   = 0;
	float rate						   = 0;
	//////////////////////////////////////////////////////////////////
	//
	// Command-line argument checking; if no argument, error out
	//
	if (argc						  <= 3)
	{
		fprintf(stderr, "ERROR: Not enough arguments\n");
		fprintf(stderr, "usage:\n");
		fprintf(stderr, "\t%s FILENAME STRIDE\n\n", argv[0]);
		exit (1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// otherwise, argument is file name to encode
	//
	else
	{
		
		in							   = fopen(argv[1], "r");
		if (in						  == NULL)
		{
			fprintf(stderr, "Error opening '%s' for reading.\n", argv[1]);
			exit (1);
		}
		// grab base name of file
		base = basename(argv[1]);
		strcat(outpath, argv[2]);
		strcat(outpath, "/");
		strcat(outpath, base);
		strcat(outpath, ".rle");
		out = fopen(outpath, "w");
		if (out == NULL)
		{
			fprintf(stderr, "Error opening '%s' for writing.\n", outpath);
			exit (1);
		}
		// using count as a temp value here instead of making new var
		count = 0x64;
		fputc(count, out);
		bO++;
		count = 0x63;
		fputc(count, out);
		bO++;
		count = 0x66;
		fputc(count, out);
		bO++;
		count = 0x58;
		fputc(count, out);
		bO++;
		count = 0x20;
		fputc(count, out);
		bO++;
		count = 0x52;
		fputc(count, out);
		bO++;
		count = 0x4c;
		fputc(count, out);
		bO++;
		count = 0x45;
		fputc(count, out);
		bO++;
		count = 0x00;
		fputc(count, out);
		bO++;	
		count = 0x02;
		fputc(count, out);
		bO++;
		count = atoi(argv[3]); // shhhhhhh
		fputc(count, out);
		bO++;
		count = strlen(base);
		fputc(count, out);
		bO++;
		for (index = 0; index < strlen(base); index++) // filename
		{
			fputc(base[index], out);
			bO++;
		}


		stride = atoi(argv[3]);
		pattern = malloc(sizeof(int) * stride);
		patternOld = malloc(sizeof(int) * stride);
	}

	for (index = 0; index < stride; index++) // grab 5 bytes
	{
		pattern[index] = fgetc(in); 
		bI++;
		patternOld[index] = pattern[index];
		if (feof(in))
		{
			EOF_FLAG = 1;
			break;
		}
	}	
	count = 1;
	//////////////////////////////////////////////////////////////////
	//
	// Your dcfX RLE v2 encoding implementation here
	//
	while (EOF_FLAG != 1) // flag to exit
	{	
		for (index = 0; index < stride; index++) // grab 5 bytes
		{
			pattern[index] = fgetc(in);
			bI++;
			if (pattern[index] == EOF)
			{
				EOF_FLAG = 1;
				DIF_FLAG = 1; // Make sure this is 1
				break;
			}
			else if (patternOld[index] != pattern[index])
			{
				DIF_FLAG = 1;
			}
		}
		if (DIF_FLAG == 1)
		{
			COUNT_FLAG = 1;
			fputc(count, out);
			bO++;
			count = 0;
			for (index = 0; index < stride; index++)
			{
				fputc(patternOld[index], out);
				bO++;
			}
			for (index = 0; index < stride; index++)
			{
				if (pattern[index] == EOF)
				{
					break;
				}
				else
				{
					COUNT_FLAG = 0;
					patternOld[index] = pattern[index];
				}
			}
			DIF_FLAG = 0;
		}
		if (count == 254) // I know this can fail outside this project but Im too deep
		{
			DIF_FLAG = 1;
		}
		count++;
	}
	if (COUNT_FLAG == 0)
	{
		count = 1;
		fputc(count, out);
	}
	index = 0;
	while (pattern[index] != EOF)
	{
		fputc(pattern[index], out);
		bO++;
		index++;
	}

	// INFORMATION
	fprintf(stdout, "   input name length: %d bytes\n", (int)strlen(argv[1]));
	fprintf(stdout, "      input filename: %s\n", argv[1]);
	fprintf(stdout, "embedded name length: %d\n", (int)strlen(base));
	fprintf(stdout, "  embedded file name: %s\n", base);
	fprintf(stdout, "  output name length: %d bytes\n", (int)strlen(outpath));
	fprintf(stdout, "     output filename: %s\n", outpath);
	fprintf(stdout, "        stride value: %d bytes\n", stride);
	fprintf(stdout, "             read in: %ld bytes\n", bI);
	fprintf(stdout, "    data written out: %ld bytes\n", bO);
	rate = ((float)bO / (float)bI ) * 100;
	fprintf(stdout, "     comression rate: %.02f", rate);
	fprintf(stdout, "%%\n");



	//////////////////////////////////////////////////////////////////
	//
	// close open file pointers
	//
	fclose(in);
	fclose(out);

	return(0);
}
