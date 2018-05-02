///////////////////////////////////////
//		0x4_
// an archive tool....

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main (int argc, char **argv)
{
	int opt   = 0;
	int index = 0;
	char c    = 0;
	char fn [255];	// file name for creating output files when 'untaring'
	FILE *df;		// dest file
	FILE *sf;		// source file
	while ((opt = getopt(argc, argv, "au")) != -1)
	{ // no tab no space left

	switch (opt)
	{
		case 'a':	
			if (argc < 2)
			{
				fprintf(stderr, "files pls\n");
				exit(1);
			}

			index = 1;
			df = fopen("archive.ar", "w"); 			
			while (argv[index] != NULL)
			{
				sf = fopen(argv[index], "r");	 // open each file
		
				fputc(2, df);					 // use STX as a marker for each file
				fputs(argv[index], df);
				fputc(':', df);
		
				while ((c = fgetc(sf)) != EOF)
					fputc(c, df);				 // write contents to dest
		
				fputc(3, df);					 // ETX for end of each file marker
				fclose(sf);
				index++;
			}
			fclose(df);	
			return (0);

		case 'u':
			if (argc < 2)
			{
				fprintf(stderr, "archive pls\n");
				exit(1);
			}
			
			while (1)
			{
			
			}
	}

	}
	return(0);
}

