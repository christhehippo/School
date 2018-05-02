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
	char fn[128]; //  = malloc(128*sizeof(char));
	char    c;
	int index;

	while (1)
	{
		while ((c = fgetc(sf)) != '~')	
		{	
			fn[index] = c;
			index++;
//			fputc(c, df); 
		}
//		break;
	}
	fprintf(stdout, "%s\n", fn);
	fclose(sf);
	return (0);
}

