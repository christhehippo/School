#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <string.h>

#define LEFTEDGE   0
#define RIGHTEDGE 70
#define ROW		  10

int main ()
{
	struct winsize terminal;
	char message[] = "Hello";
	char blank[]   = "   ";
	int  dir	   = 1;
	int  pos	   = LEFTEDGE;
	int  y		   = 0;
	int width, height;

	ioctl (0, TIOCGWINSZ, &terminal);
	width  = terminal.ws_col;
	height = terminal.ws_row;;
	

	initscr ();

	if (has_colors() == FALSE)
	{
		endwin ();
		fprintf (stdout, "Your terminal does not support color\n");
		exit (1);
	
	}
	start_color ();
	init_pair (1, COLOR_RED, COLOR_BLACK);
	init_pair (2, COLOR_GREEN, COLOR_BLACK);
	init_pair (3, COLOR_YELLOW, COLOR_BLACK);
	init_pair (4, COLOR_BLUE, COLOR_BLACK);
	init_pair (5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair (6, COLOR_CYAN, COLOR_BLACK);
	init_pair (7, COLOR_WHITE, COLOR_BLACK);

	attron (COLOR_PAIR(1));


	while (1)	// Main game loop
	{
		attron (COLOR_PAIR(c));
		move (y, pos);
		addstr (message);
		move (LINES-1, COLS-1);
		refresh ();
		usleep (50000);
		y = y + 1;
		move (y, pos+3);
		addstr (blank);
		pos = pos + dir;

		if (pos >= width -strlen(message))
		{
			attroff (COLOR_PAIR(c));
			c = c + + 1;
			if (c < 7)
				c = 1;
			attron (COLOR_PAIR(c));
			dir = -1;
		}	

		if (pos <= LEFTEDGE)
			dir = 1;
		if (y > height)
			y=0;

	}
	attroff (


	return (0);
}
