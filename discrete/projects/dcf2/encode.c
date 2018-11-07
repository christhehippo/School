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
    FILE *in                           = NULL;
    FILE *out                          = NULL;
	char *path						   = malloc(sizeof(char) * 64);
	char *base						   = malloc(sizeof(char) * 64);
	char *inBase					   = malloc(sizeof(char) * 64);
	char *pattern					   = NULL;
	char *patternOld				   = NULL;
	int   count 					   = 0;
	int   stride					   = 0;
	int   control					   = 0;
	int   i							   = 0;
	int   dif_flag					   = 0;
	int   eof_flag					   = 0;
	long long bi				  	   = 0; // bytes in / out
	long long bo				       = 0;

	//////////////////////////////////////////////////////////////////
	//
	// Command-line argument checking; if no argument, error out
	//
    if (argc                          <= 4)
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
        in                             = fopen(argv[1], "r");
        if (in                        == NULL)
        {
            fprintf(stderr, "Error opening '%s' for reading.\n", argv[1]);
            exit (1);
        }
		
		stride  = atoi(argv[3]);
		control = atoi(argv[4]);
		
		base						   = argv[1];
		base						   = basename(base);
		inBase 						   = base;
		path						   = argv[2];
		strcat(path, base);
		strcat(path, ".rle");
		out							   = fopen(path, "w");
		if (out						  == NULL)
		{
			fprintf(stderr, "Error opening '%s' for writing.\n", path);
			exit (2);
		}

    }

	//////////////////////////////////////////////////////////////////
	//
	// Your dcfX RLE v2 encoding implementation here
	//
	
	count = 0x64;
	fputc(count, out);
	bo++;
	count = 0x63;
	fputc(count, out);
	bo++;
	count = 0x66;
	fputc(count, out);
	bo++;
	count = 0x58;
	fputc(count, out);
	bo++;
	count = 0x20;
	fputc(count, out);
	bo++;
	count = 0x52;
	fputc(count, out);
	bo++;
	count = 0x4c;
	fputc(count, out);
	bo++;
	count = 0x45;
	fputc(count, out);
	bo++;;
	fputc(control, out);
	bo++;
	count = 0x03;
	fputc(count, out);
	bo++;
	fputc(stride, out);
	bo++;
	count = strlen(inBase);
	fputc(count, out);
	bo++;

	for (i = 0; i < strlen(inBase); i++)
	{
		fputc(inBase[i], out);
		bo++;
	}
	// header done ^^^^^
	pattern    = malloc(sizeof(char) * stride); // allocate pattern array
	patternOld = malloc(sizeof(char) * stride);

	for (i = 0; i < stride; i++)
	{	// get the starting pattern
		patternOld[i] = fgetc(in);
		bi++;
	}
	count = 1;	
	while (!feof(in))
	{
		for (i = 0; i < stride; i++)
		{
			pattern[i] = fgetc(in);
			bi++;
			if (pattern[i] == EOF)
				if (feof(in))
					eof_flag = 1;
		}
		
		for (i = 0; i < stride; i++)
		{
			if (patternOld[i] != pattern[i])
			{
				dif_flag = 1;
			}
		}
		if (count == 254)
		{
			dif_flag = 1;
			count++;
		}

		if (dif_flag == 0)
		{
			count++;
		}
		else
		{
			if (count == 1)
			{
				for (i = 0; i < stride && eof_flag != 1; i++)
				{
					fputc(patternOld[i], out);
					bo++;
					patternOld[i] = pattern[i];
				}
				count = 1;
			}
			else if (count > 1)
			{
				fputc(control, out);
				bo++;
				fputc(count,   out);
				bo++;
				count = 1;
				fputc(stride,  out);
				bo++;
				for (i = 0; i < stride; i++)
				{
					fputc(patternOld[i], out);
					bo++;
					patternOld[i] = pattern[i];
				}
			}
			dif_flag = 0;
			if (eof_flag == 1) // if we had a count of 1+, we put those in then exit loop
				break;
		}
	}
	for (i = 0; i < stride; i++)
	{
		fputc(patternOld[i], out);
		bo++;
	}
	i = 0;
	while (pattern[i] != EOF)
	{
		fputc(pattern[i], out);
		bo++;
		i++;
	}
	

	//////////////////////////////////////////////////////////////////
	//
	// close open file pointers
	//
    fclose(in);
    fclose(out);

    return(0);
}
