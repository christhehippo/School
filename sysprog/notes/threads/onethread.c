#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 5

void print_msg(char *);

int main()
{
	print_msg("hello");
	print_msg("world\n");
	
	return(0);
}

void print_msg(char *message)
{
	int index = 0;
	for (index = 0; index < NUM; index++)
	{
		fprintf(stdout, "%s", message);
		fflush (stdout);

		sleep(1);
	}
	
}
