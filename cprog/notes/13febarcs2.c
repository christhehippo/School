#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv)
{
	short int x = 0;
	short int y = 0;
	
	fprintf(stdout, x addr: %p, y addr: %p\n", &x, &y);
	fprintf(stdout, "This program (%s) was run with %d arguments\n", *(argv+0), argc);
	//argv[0]
	fprintf(stdout, "Those arguements are: \n");
	for (x = 0; x < argc; x++)
	{
		fprintf(stdout, "*(argv+%hd): \"%s\" (length: %lu)\n", x, *(argv+x), strlen(*(argv+x)));
		for (y = 0; y < strlen(*(argv+x)); y++)
		{
			fprintf(stdout, "\t*(*(argv+%hd)+%hd): '%c'\n",
							x, y, *(*(argv+x)+y));
		}
	}
	return (0);

}
