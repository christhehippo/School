///////////////////////////////////////
//		0x4_archiver
// an archive tool....
//
// I had trouble with this and decided to just make 
// one program to combine files and one to uncombine 
//
// This will take all the files and mash them together,
// placing ascii 2 'start of text' for start markers 
// and ascii 3 'end of text' for end markers, thats how
// it will unmash them. 

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int index = 0;
	char c    = 0;
	FILE *df;		// dest file
	FILE *sf;		// source file
	
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
		
//		fputc(2, df);					 // use STX as a marker for each file
		fputs(argv[index], df);
		fputc(':', df);
		
		while ((c = fgetc(sf)) != EOF)
			fputc(c, df);				 // write contents to dest
		
		fputc('~', df);				 // ETX for end of each file marker
		fclose(sf);
		index++;
	}
	fclose(df);	
		
	return(0);
}

