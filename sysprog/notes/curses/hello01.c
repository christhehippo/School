#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int main ()
{
	int x = 0;
	initscr ();  				// main scren turn on
	clear ();	 				// clear the screen

	move (10, 20);  			// row10 (x), col20 (y)
	addstr ("Hello, World\n");  // set us up the bomb
	for (x = 0; x < 20; x++)
	{
		move (5, 60);				// row5, col20
		standout ();
		addstr ("What happen!!?\n");
		standend ();	
		refresh ();
		sleep (1);
//		clear ();
		move (5, 60);				// row5, col20
		addstr ("What happen!!?\n");
		refresh ();	
		sleep (1);
//		clear ();

	}
	move (LINES-1, 0);			// move to the strat of the last line

	refresh ();					// repaint the screen
 	getch ();					// wait for user input

	endwin ();					// main screen turn off


	return (0);
}	
