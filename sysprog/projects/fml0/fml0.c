#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include <time.h>
#include <signal.h>

#define UP 	  0
#define DOWN  1
#define LEFT  2
#define RIGHT 3
#define THING 48
#define HEAD  64
#define FOOD  '$'


void drawThing();
void bounds();
void end();
void update();
void startScreen();
void drawScore(int score);

int max_y;					
int max_x;
int     y;
int     x;
int   dir; 
int score;
int pos_x[100];
int pos_y[100];
int rand_x;
int rand_y;


int main()
{
	struct winsize window;		// window sizing
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	max_y = window.ws_row;		// max y val
	max_x = window.ws_col;		// max x
	
	y     	 = 5;				// starting position
	x     	 = 15;
	pos_y[0] = y;
	pos_x[0] = x;
	pos_y[1] = y;
	pos_x[1] = x-1;
	rand_y   = 10;
	rand_x   = 20;
	score 	 = 1;
	dir   	 = RIGHT;			// starting direction
	char ch;					// store input here

	srand(time(NULL));//initialize random num seed

//	printf("max_x: %d   max_y: %d   x: %d   y: %d\n", max_x, max_y, x, y);
	
	initscr();					// start curses
	noecho();					// no echoing
	curs_set(FALSE);			// hide cursor
	cbreak();					// no getchar pause
	signal (SIGINT, SIG_IGN);	// ignore interupt signals


	start_color();				// color function
	init_pair (1, COLOR_RED, COLOR_BLACK);
	init_pair (2, COLOR_GREEN, COLOR_BLACK);
	init_pair (3, COLOR_YELLOW, COLOR_BLACK);
	init_pair (4, COLOR_BLUE, COLOR_BLACK);
	init_pair (5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair (6, COLOR_CYAN, COLOR_BLACK);
	init_pair (7, COLOR_WHITE, COLOR_BLACK);

	
	startScreen();

	clear();	
	refresh();
	while (1)
	{
		
		// paint a picture
		drawThing();
		drawScore(score);
		// direction control
		ch = getch();
		timeout(300);
		usleep(500);
		if (ch == 'a')
		{
			if (dir == RIGHT)
			{
				usleep(500);
			}
			else
			{
				dir = LEFT;
				usleep(500);
			}
		}
		else if (ch == 's')
		{
			if (dir == UP)
			{
				usleep(500);
			}
			else
			{
				dir = DOWN;
				usleep(500);
			}
		}
		else if (ch == 'd')
		{
			if (dir == LEFT)
			{
				usleep(500);
			}
			else
			{
				dir = RIGHT;
				usleep(500);
			}
		}
		else if (ch == 'w')
		{
			if (dir == DOWN)
			{
				usleep(500);
			}
			else
			{
				dir = UP;
				usleep(500);
			}
		}
		else if (ch == 'Q')		// quit on shift+q
			end();
		

		bounds();				// check if we lost
	}

	endwin();					// restore terminal
	return (1);					// should not reach this place
}

void bounds()
{
	int index = 0;

	if (pos_x[0] == -1)			// check for wall colision
		end();
	if (pos_x[0] == (max_x + 1))
		end();
	if (pos_y[0] == -1)
		end();
	if (pos_y[0] == (max_y + 1))
		end();
	
	for (index = score; index > 0; index--)
	{
		// check for collision with self 
		if ((pos_x[0] == pos_x[index]) && (pos_y[0] == pos_y[index]))
			end();
	}

}
void update() // function to refresh the coordinates (direction update)
{
	int index = 0;

	if (dir == UP)					// update coords
		y--;
	if (dir == DOWN)
		y++;
	if (dir == LEFT)
		x--;
	if (dir == RIGHT)
		x++;
	
	if ((x == rand_x) && (y == rand_y))  // score check
	{
		score++;
		rand_x = rand() % (max_x-1); // new food generate
		rand_y = rand() % (max_y-1);
	}

	for (index = score; index > 0; index--)
	{
		pos_x[index] = pos_x[index-1]; // update body positions in array
		pos_y[index] = pos_y[index-1];
	}
	pos_x[0] = x; 				       // new head coords
	pos_y[0] = y;

}	

void drawThing() // function to draw snake
{
	int index = 0;
	int c	  = 1;
	clear();
	attron(COLOR_PAIR(5));
	mvaddch(rand_y, rand_x, FOOD);			  // draw food
	attroff(COLOR_PAIR(5));
	mvaddch(y, x, THING);
	refresh();
	attron(COLOR_PAIR(c));					  // unique char for head
	mvaddch(pos_y[0], pos_x[0], HEAD);
	attroff(COLOR_PAIR(c));
	refresh();
	c++;
	for (index = 1; index <= score; index++)  // draw all elements of body arrays
	{
		attron(COLOR_PAIR(c));
		mvaddch(pos_y[index], pos_x[index], THING); // draw piece of body
		refresh();
		attroff(COLOR_PAIR(c));
		c++;
		if (c > 7) // color chooser
			c = 1;
	}
	update();
}

void end() // function to end program
{
	clear();
	refresh();
	mvaddstr(max_y/2, (max_x/2)-4, "Game Over");
	refresh();
	usleep(50000);
	getchar();
	endwin();
	exit(0);
}

void startScreen()
{
	clear();
	refresh();

	mvaddstr(max_y/2, (max_x/2)-3, "SNAKE");
	refresh();
	mvaddstr((max_y)+1, (max_x/2)-10, "PRESS ANY KEY TO START");
	refresh();
	usleep(50000);
	getchar();

}

void drawScore(int score)
{
	mvaddstr(max_y-1, 0, "SCORE: ");
	mvprintw(max_y-1, 9, "%d", score);
	refresh();

}



