

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>


int main (int argc, char *argv)
{
	//terminal dectection stuff
	struct winsize terminal;
    ioctl  (0, TIOCGWINSZ, &terminal);
		 
    printf ("lines:   %d\n", terminal.ws_row);
    printf ("columns: %d\n", terminal.ws_col);
	if (terminal.ws_row < 20)
	{
		fprintf(stderr, "Error: terminal height is less than 20 lines!\n");
		return(1);
	}
	if (terminal.ws_col < 80)
	{
		fprintf(stderr, "Error: terminal width is less than 80 collumns!\n");
		return (2);
	}


	FILE *input = argv[1];
	
	input = fopen("input", "r");







	return (0);
}
