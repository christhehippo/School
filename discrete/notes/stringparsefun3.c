#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int main (int argc, char **argv)
{
	size_t len    = 0;
	int    pos    = 0;
	char *filestr = NULL;
	char *tmpstr  = NULL;

	fprintf(stdout, "Our name is: %s\n", *(argv+0));
	fprintf(stdout, "Arg #1   is: %s\n", *(argv+1)); 
	
	//
	// Idea #2: basename this mofo 
	//
	
	tmpstr = basename((*argv+0));

	fprintf(stdout, "tmpstr: %s\n", tmpstr);

	return (0);

	
}
