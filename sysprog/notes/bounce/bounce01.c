#include <signal.h>
#include <stdlib.h>
#include <ncurses.h>
#include "bounce.h"
#include <sys/time.h>

struct ppball the_ball;

int  set_ticker (int);
void set_up ();
void wrapup ();
int bounce_or_lose (struct ppball *bp);

int main ()
{
	int  c  = 0;

	set_up ();

	while ((c = getchar()) != 'Q')  // main game loop
	{
		if (c == 'f')
		{
			the_ball.x_ttm--;
		}
		else if (c == 's')
		{			
			the_ball.x_ttm++;
		}
		else if (c == 'F')
		{
			the_ball.y_ttm--;
		}
		else if (c == 'S')
		{	
			the_ball.y_ttm++;
		}
	}
	wrapup ();

	return (0);
}

void set_up ()
{
	void  ball_move (int);

	the_ball.y_pos   = Y_INIT;
	the_ball.x_pos   = X_INIT;
	the_ball.y_ttg   = the_ball.y_ttm  = Y_TTM;
	the_ball.x_ttg   = the_ball.x_ttm  = X_TTM;
	the_ball.y_dir   = 1;
	the_ball.x_dir   = 1;
	the_ball.symbol  = DFL_SYMBOL;

	initscr ();
	noecho  ();
	crmode  ();

	signal  (SIGINT, SIG_IGN);

	mvaddch (the_ball.y_pos, the_ball.x_pos, the_ball.symbol);

	refresh();

	signal  (SIGALRM, ball_move);
	set_ticker  (1000 / TICKS_PER_SEC);
}

void wrapup ()
{
	set_ticker (0);
	endwin ();
}

void ball_move (int signum)
{
	int  y_cur, x_cur, moved;

	signal (SIGALRM, SIG_IGN);  // critical section begins

	y_cur  					= the_ball.y_pos;
	x_cur  					= the_ball.x_pos;

	moved  =0;

	if ((the_ball.y_ttm >    0) &&
		(the_ball.y_ttg-- == 1))
	{
		the_ball.y_pos 	  += the_ball.y_dir;
		the_ball.y_ttg     = the_ball.y_ttm;
		moved			   = 1;
	}
	
	if ((the_ball.x_ttm >    0) &&
		(the_ball.x_ttg-- == 1))
	{
		the_ball.x_pos 	  += the_ball.x_dir;
		the_ball.x_ttg     = the_ball.x_ttm;
		moved			   = 1;
	}
	
	if (moved)
	{
		mvaddch (y_cur, x_cur, BLANK);
		mvaddch (y_cur, x_cur, BLANK);
		mvaddch (the_ball.y_pos, the_ball.x_pos, the_ball.symbol);
		bounce_or_lose (&the_ball);
		move (LINES-1, COLS-1);
		refresh ();
	}
	signal (SIGALRM, ball_move); //  critical setion ends
}

int bounce_or_lose (struct ppball *bp)
{
	int  return_val  = 0;

	if (bp -> y_pos == TOP_ROW)
	{	
		bp -> y_dir  = 1;
		return_val   = 1;
	}
	else if (bp -> y_pos == BOT_ROW)
	{	
		bp -> y_dir  = -1;
		return_val   = 1;
	}
	
	if (bp -> x_pos == TOP_ROW)
	{	
		bp -> x_dir  = 1;
		return_val   = 1;
	}
	else if (bp -> x_pos == BOT_ROW)
	{	
		bp -> x_dir  = -1;
		return_val   = 1;
	}

	return (return_val);
}

int set_ticker (int n_msecs)
{
	struct itimerval new_timeset;
	long   int 		 n_secs;
	long   int 		 n_usecs;

	n_secs   =  n_msecs  / 1000;
	n_usecs	 = (n_msecs  % 1000) * 1000L;

	new_timeset.it_interval.tv_sec  = n_secs;
	new_timeset.it_interval.tv_usec = n_usecs;
	new_timeset.it_value.tv_sec  = n_secs;
	new_timeset.it_value.tv_usec = n_usecs;

	return (setitimer (ITIMER_REAL, &new_timeset, NULL));

}
