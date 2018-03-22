#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define LEFTEDGE  0
#define RIGHTEDGE 75
#define ROW       10

int main ()
{
	struct winsize terminal;
	char message[] = "Hello";
	char blank[]   = "   ";
	int  dir       = 1;
	int  pos       = LEFTEDGE;
	int  y         = 0;
	int  ydir      = 1;
	int  width, height;
	int  c         = 1;

	initscr ();

	if (has_colors() == FALSE)
	{
		endwin();
		fprintf (stdout, "Your terminal does not support color\n");
		exit (1);
	}
	// http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html
	start_color ();
	init_pair (1, COLOR_RED, COLOR_BLACK);
	init_pair (2, COLOR_GREEN, COLOR_BLACK);
	init_pair (3, COLOR_YELLOW, COLOR_BLACK);
	init_pair (4, COLOR_BLUE, COLOR_BLACK);
	init_pair (5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair (6, COLOR_CYAN, COLOR_BLACK);
	init_pair (7, COLOR_WHITE, COLOR_BLACK);

	while (1)   // main game loop
	{
		attron (COLOR_PAIR(c));
		ioctl (0, TIOCGWINSZ, &terminal);
		width = terminal.ws_col;
		height = terminal.ws_row;

		move (y, pos);
		addstr (message);
		move (LINES-1, COLS-1);
		refresh ();
		usleep (30000);
		y = y + ydir;
		move (y, pos+3);
		addstr (blank);
		pos = pos + dir;

		if (pos >= width - strlen(message))
		{
			attroff (COLOR_PAIR(c));
			c = c + 1;
			if (c > 7)
				c = 1;
			attron (COLOR_PAIR(c));
			dir = -1;
		}

		if (pos <= LEFTEDGE)
		{
			attroff (COLOR_PAIR(c));
			c = c + 1;
			if (c > 7)
				c = 1;
			attron (COLOR_PAIR(c));
			dir = 1;
		}
		if (y > height)
		{	
			ydir = -1;
			
		}
		if (y < 0)
			ydir = 1;;
	}
	attroff (COLOR_PAIR(c));
	return (0);
}
