// I can't figure out the issue with the bmp file
// theres a lot of values that are different by one
// which makes no sense to me, I have read a lot about 
// fgetc and fputc and I can't find a similar issue
// so I guess the issue is somewhere else. 

// I am leaning towards a problem with the bmp file format.
// I can decode it but not encode it. I am missing a few hundred bytes
// from my file.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////
    //
    // Variable declarations
    //
    FILE *in                         = NULL;
    FILE *out                        = NULL;
    char *filename                   = argv[2];
    char *basename                   = argv[1];
	unsigned int   c			    	 = 0;
	unsigned int tmp     	 		   	 = 0;
	signed int count				 = 0;
	int  nameLength                  = 0;
	int  index						 = 0;
	long bytesIn					 = 0;
	long bytesOut 					 = 0;
	float compressionRate			 = 0;
    //////////////////////////////////////////////////////////////////
    //
    // Command-line argument checking; if no argument, error out
    //
    if (argc                        == 1)
    {
        fprintf(stderr, "Error\n");
    }

    //////////////////////////////////////////////////////////////////
    //
    // otherwise, argument is file name to encode
    //
    else
    {
        in                           = fopen(basename, "r+b");
        if (in                      == NULL)
        {
            fprintf(stderr, "Error opening '%s' for reading.\n", basename);
            exit (1);
        }
		out 						 = fopen(filename, "w+b");
		if (out						== NULL)
		{
			fprintf(stderr, "Error creating output file.\n");
			exit (2);
		}
    }

    //////////////////////////////////////////////////////////////////
    //
    // Your dcfX RLE v1 encoding implementation here
    //
		// place 'header' bytes
		c = 0x64;
		fputc(c, out);
		c = 0x63;
		fputc(c, out);
		c = 0x66;
		fputc(c, out);
		c = 0x58;
		fputc(c, out);
		c = 0x20;
		fputc(c, out);
		c = 0x52;
		fputc(c, out);
		c = 0x4c;
		fputc(c, out);
		c = 0x45;
		fputc(c, out);
		c = 0x00;
		fputc(c, out);
		c = 0x01;
		fputc(c, out);
		c = 1;
		fputc(c, out);
		bytesOut = 11;
		while (basename[nameLength] != '\0')
		{ // get the length of the name of the source file
			nameLength++;
		}
		c = nameLength; 
		fputc(c, out);
		bytesOut++;
		while (index < nameLength)
		{ // write the original filename to encoded file 
			c = basename[index];
			fputc(c, out);
			bytesOut++;
			index++;
		}
		
		// now collect data from source file
		c     = fgetc(in); // collect first byte
//		bytesIn = 1;
		count = 1;
		
		while (!feof(in)) // exit once the EOF is written to the file
		{
			tmp = fgetc(in); // grab a byte
			bytesIn++;
			if (c == tmp)    // if it is the same as c, up its count
			{
				count++;
			}
			else // write to file how many and what then reset
			{
	//			fprintf(stdout, "putting %hhd %hhd in file\n", count, c);
				fputc(count, out);
				fputc(c,     out);
				bytesOut+=2;
				count = 1;
				c = tmp;
				if (feof(in))
					if (tmp == EOF)
						break;
			}
		}
		
		// output stuff
		fprintf(stdout, " input name length: %d bytes\n", nameLength);
		fprintf(stdout, "    input filename: %s\n", basename); 

		for (nameLength = 1; filename[nameLength-1] != '\0'; nameLength++)
		{
		}
		fprintf(stdout, "output name length: %d\n", nameLength);
		fprintf(stdout, "   output filename: %s\n", filename);
		fprintf(stdout, "      stride value: 1 byte\n");
		fprintf(stdout, "           read in: %ld\n", bytesIn);
		fprintf(stdout, "         wrote out: %ld\n", bytesOut);
		compressionRate = (1 - ((float)bytesOut/(float)bytesIn)) * 100;
		fprintf(stdout, "  compression rate: %.2f%\n", compressionRate);
	
    //////////////////////////////////////////////////////////////////
    //
    // close open file pointers
    //
    fclose(in);
    fclose(out);

    return(0);
}
