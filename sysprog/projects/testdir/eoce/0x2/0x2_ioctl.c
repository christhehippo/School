/////////////////////////////////////////////////////
//		0x2_ioctl
//  sort of both ioctl and terminal management
//

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>

int main ()
{
	int fd = 0;
	char c;
	struct winsize argp;
	ioctl(fd, TIOCGWINSZ, &argp);
	fprintf(stdout, "Your terminal is %hu by %hu.\n", argp.ws_row, argp.ws_col);
	
	fprintf(stdout, "Press enter and it will change size.\n");
	fscanf(stdin, "%c", &c);
	argp.ws_row+=20; 
	argp.ws_col+=20;
	ioctl(fd, TIOCSWINSZ, &argp);

	fprintf(stdout, "Your terminal is now %hu by %hu.\nPress enter to put it back.\n", argp.ws_row, argp.ws_col);
	fscanf(stdin, "%c", &c);

	argp.ws_row-=20; 
	argp.ws_col-=20;
	ioctl(fd, TIOCSWINSZ, &argp);

	fprintf(stdout, "Your terminal is now %hu by %hu.\n", argp.ws_row, argp.ws_col);

	return(0);
}
