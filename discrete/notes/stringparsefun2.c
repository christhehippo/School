#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
	size_t len    = 0;
	int    pos    = 0;
	char *filestr = NULL;
	char *tmpstr  = NULL;

	fprintf(stdout, "Our name is: %s\n", *(argv+0));
	fprintf(stdout, "Arg #1   is: %s\n", *(argv+1)); 
	
	//
	// Idea #2: Tokenize the string 
	//
	tmpstr = strtok(*(argv+0), "/");
	fprintf(stdout, "tmpster is: %s\n", tmpstr);
	while (tmpstr != NULL)
	{
		filestr = tmpstr;
		tmpstr = strtok(NULL, "/");
	}

	fprintf(stdout, "filestr: %s\n", *(argv+0));

	return (0);

	
}
