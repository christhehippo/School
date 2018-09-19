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
	// Idea #1: Isolate name by scanning string to a '/'
	//
	len = strlen(*(argv+0));
	pos = len - 1; // position of last actual symbol in string 
	fprintf(stdout, "*argv+0 is %lu bytes long\n", len);
	fprintf(stdout, "pos %lu is: '%c'\n", len, *(*(argv+0)+(len-1)));

	while ((pos >=0) && ((*(*(argv+0)+pos)) != '/'))
	{
		pos = pos - 1;
	}
	if (*(*(argv+0)+pos) == '/')
		pos = pos + 1;

	fprintf(stdout, "char is: '%c'\n", *(*(argv+0)+pos));
	
	fprintf(stdout, "filename is: %s\n", (*(argv+0)+pos));

	len = strlen((*argv+0)+pos);

	tmpstr = (char *)malloc(sizeof(char) * len + 1);

	sprintf(tmpstr, "%s", (*(argv+0)+pos));

	fprintf(stdout, "%s\n", tmpstr);

	filestr = (char *)malloc(strlen(tmpstr) + 5);
	sprintf(filestr, "out/%s", tmpstr);

	fprintf(stdout, "%s\n", filestr);

	return (0);

	
}
