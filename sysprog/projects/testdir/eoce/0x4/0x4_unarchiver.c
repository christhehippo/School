///////////////////////////////////
//		0x4_unarchiver
//  program to undo the archiving done in
//	0x4_archiver


#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Provide a file\n");
		exit(1);
	}
	
	FILE* df;
	FILE* sf   = fopen(argv[1], "r");
	char buf[128]; // contents from sf 
	char fn[128];  // file name
	char    c;
	int index = 0;

	while (1)  // continue until nothing in file sf
	{
		while (1) // get the file name
		{
			c = fgetc(sf);
			if (c == ':')
				break;
			fn[index] = c;
			index++;
		}
		df = fopen(fn, "w"); //  create the file
		index = 0;
		while (1) //  fill the file
		{
			c= fgetc(sf);
			if (c == EOF)
				break;
			if (c == '~')
				break;
			buf[index] = c;
			index++;
		}
		index = 0;
		fputs(buf, df);
		fclose(df);
		if (c == EOF)	// end 
			break;
	}
//	fprintf(stdout, "%s\n", fn);
	fclose(sf);
	return (0);
}

