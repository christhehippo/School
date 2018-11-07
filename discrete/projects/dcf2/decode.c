#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////
    //
    // variables
    //
    FILE          *in                    = NULL;
    FILE          *out                   = NULL;
    char          *filename              = NULL;
	char  		  *filepath				 = malloc(sizeof(char) * 64);
	char 		  *pattern				 = NULL;
	unsigned char  header[12];
	long long 	   bi 					 = 0;
	long long      bo 					 = 0;
	int 		   i				     = 0;
	int 		   i2					 = 0;
	int 		   control				 = 0;
	int 		   stride				 = 0;
	int			   byteCount			 = 0;
	int 		   c					 = 0;
	int			   c2					 = 0;
	int			   c3					 = 0;

    //////////////////////////////////////////////////////////////////
    //
    // process command-line, no arguments get an error
    //
    if (argc                            <  2)
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
        in                               = fopen(argv[1], "r");
        if (in                          == NULL)
        {
            fprintf(stderr, "Error opening '%s' for reading\n", argv[1]);
            exit (1);
        }
    }
	for (i = 0; i < 12; i++)
	{
		header[i] = fgetc(in);
		bi++;
	}
	filename = malloc(sizeof(char) * header[11]);
	for (i = 0; i < header[11]; i++)
	{
		filename[i] = fgetc(in);
		bi++;
	}
	filepath = argv[2];
	strcat(filepath, filename);
	printf("opening %s for writing\n", filepath);
	out = fopen(filepath, "w");
	if (out == NULL)
	{
		fprintf(stderr, "Error opening '%s' for writing.\n", filename);
		exit (2);
	}
	stride  = header[10];
	control = header[ 8];
	pattern = malloc(sizeof(char) * stride);

    //////////////////////////////////////////////////////////////////
    //
    // your dcfX RLE v2 decoding implementation
    //
	
	while (!feof(in))
	{
		if (header[9] == 0x01)
		{

		}
		else if (header[9] == 0x02)
		{

		}
		else if (header[9] == 0x03)
		{
			c  = fgetc(in);
			bi+=1;
			if (c == control)
			{
				byteCount = fgetc(in);
				c2 = fgetc(in);
				if (c2 == stride)
				{
					for (i = 0; i < stride; i++)
					{
						pattern[i] = fgetc(in); // collect the pattern
					}
					for (i = 0; i < byteCount; i++)
					{
						for (i2 = 0; i2 < stride; i2++)
						{
							fputc(pattern[i2], out);
							bo++;
						}
					}
				}
				else if (byteCount == control)
				{
					fputc(c, out);
					bo++;
					c = byteCount;
					byteCount = c2;
					fgetc(in); // skip stride
					bi++;
				
					for (i = 0; i < stride; i++)
					{
						pattern[i] = fgetc(in); // collect the pattern
					}
					for (i = 0; i < byteCount; i++)
					{
						for (i2 = 0; i2 < stride; i2++)
						{
							fputc(pattern[i2], out);
							bo++;
						}
					}
				}
				else if (c2 == control)
				{
					fputc(c, out);
					fputc(byteCount, out);
					bo+=2;
					c = c2;
					byteCount = fgetc(in);
					fgetc(in); // stride skip, making assumptions here..
					
					for (i = 0; i < stride; i++)
					{
						pattern[i] = fgetc(in); // collect the pattern
					}
					for (i = 0; i < byteCount; i++)
					{
						for (i2 = 0; i2 < stride; i2++)
						{
							fputc(pattern[i2], out);
							bo++;
						}
					}
				}
				else
				{
					fputc(c, out);
					bo++;
					if (byteCount != EOF)
					{
						fputc(byteCount, out);
					}
					if (c2 != EOF)
					{
						fputc(c2, out);
						bo++;
					}
				}
			}
			else
			{
				if (c != EOF)
				{
					fputc(c, out);
					bo++;
				}
			}
		}
	}



    //////////////////////////////////////////////////////////////////
    //
    // close our open files
    //
    fclose(in);
    fclose(out);

    return(0);
}
