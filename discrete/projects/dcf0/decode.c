#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////
    //
    // variables
    //
    FILE          *in                  = NULL;
    FILE          *out                 = NULL;
    char          *filename            = NULL;
    unsigned char  header[12];
	int index						   = 0;
    int 		 c   				   = 0;
	int 		 count				   = 0;
	long bytesIn					   = 0;
	long bytesOut					   = 0;
	float iRate						   = 0;
	int outLength					   = 0;
	int inLength					   = 0;
	//////////////////////////////////////////////////////////////////
    //
    // process command-line, no arguments get an error
    //
    if (argc                          <  2)
    {
        fprintf(stderr, "Error\n");
    }

    //////////////////////////////////////////////////////////////////
    //
    // if given, open specified file for reading
    //
    else
    {
        in                             = fopen(argv[1], "r");
        if (in                        == NULL)
        {
            fprintf(stderr, "Error opening '%s' for reading\n", argv[1]);
            exit (1);
        }
		out 						   = fopen(argv[2], "w");
		if (out 					  == NULL)
		{
		    fprintf(stderr, "Error opening '%s' for writing\n", argv[1]);
            exit (2);
		}
    }

    //////////////////////////////////////////////////////////////////
    //
    // your dcfX RLE v1 decoding implementation
    //

	// Fill the header array
	for (index = 0; index < 12; index++)
	{
		header[index] = fgetc(in);
		bytesIn++;
//		fprintf(stdout, "header[index]: %x\n", header[index]);
	}
	
	// initialize and fill the output name array
	filename = (char *)malloc(sizeof(char) * header[11]);
	for (index = 0; index < header[11]; index++)
	{
		filename[index] = fgetc(in);
		bytesIn++;
	}
	// write the characters to the file
	while (1)
	{
		count = fgetc(in);
		c     = fgetc(in);
		bytesIn+=2;
		if (feof(in))
		{
			bytesIn-=2;
			break;
		}
//		fprintf(stdout, "count = %hhd  char = %c\n", count, c);
		for (index = 0; index < count; index++)
		{
			fputc(c, out);
			bytesOut++;
		}
	}
	for (inLength = 1; argv[1][inLength-1] != '\0'; inLength++)
	{
	}
	fprintf(stdout, " input name length: %d\n", inLength);
	fprintf(stdout, "    input filename: %s\n", argv[1]);
	for (outLength = 1; argv[2][outLength-1] != '\0'; outLength++)
	{
	}
	fprintf(stdout, "output name length: %d\n", outLength-1);
	fprintf(stdout, "   output filename: %s\n", argv[2]);
	fprintf(stdout, "     stride length: 1\n");
	fprintf(stdout, "           read in: %ld\n", bytesIn);
	fprintf(stdout, "         wrote out: %d\n", bytesOut);
	iRate = (((float)bytesOut / (float)bytesIn) - 1) * 100;
	fprintf(stdout, "    inflation rate: %.2f%\n", iRate);

	//////////////////////////////////////////////////////////////////
    //
    // close our open files
    //
    fclose(in);
    fclose(out);

    return(0);
}
