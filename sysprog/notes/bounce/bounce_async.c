#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define  MESSAGE "hello"
#define  BLANK   "     "

int  set_ticker (int);
void set_up ();
void wrapup ();
void on_input (int);
void on_alarm (int);
void enable_kbd_signals(void);

int  row;
int  col;
int  dir;
int  delay;
int  done;

int  main ()
{
	row    =  10;
	col    =   0;
	dir    =   1;
	delay  = 200;
	done   =   0;

	set_up ();

	while (!done)
	{
		pause ();
	}
	wrapup ();

	return (0);
}

void set_up ()
{
	initscr ();
	crmode  ();
	noecho  ();
	clear   ();

	signal  (SIGIO,  on_input);
	enable_kbd_signals();

	signal  (SIGINT, SIG_IGN);

	signal  (SIGALRM, on_alarm);
	set_ticker (delay);

	move (row, col);
	addstr (MESSAGE);
	refresh ();
}

void wrapup ()
{
	set_ticker (0);
	endwin ();
}

int set_ticker (int n_msecs)
{
	struct itimerval new_timeset;
	long   int       n_sec;
	long   int       n_usecs;

	n_sec    = n_msecs  / 1000;
	n_usecs  = (n_msecs % 1000) * 1000L;

	new_timeset.it_interval.tv_sec   = n_sec;
	new_timeset.it_interval.tv_usec  = n_usecs;
	new_timeset.it_value.tv_sec      = n_sec;
	new_timeset.it_value.tv_usec     = n_usecs;

	return (setitimer (ITIMER_REAL, &new_timeset, NULL));
}

void on_input (int signum)
{
	int  c  = 0; 

	signal (SIGIO, on_input);
	c       = getch();

	if ((c == 27) ||
		(c == EOF))
	{
		done  = 1;
	}
	else if (c == ' ')
	{
		dir   = -dir;
	}
}

void on_alarm (int signum)
{
	signal (SIGALRM, on_alarm);
	mvaddstr (row, col, BLANK);
	col += dir;
	mvaddstr (row, col, MESSAGE);
	refresh ();

	if ((dir == -1) &&
		(col <=  0))
	{
		dir   =  1;
	}
	else if ((dir == 1) &&
		     (col+strlen (MESSAGE) >= COLS))
	{
		dir   = -1;
	}
}

void enable_kbd_signals()
{
	int fd_flags  = 0;

	fcntl (0, __F_SETOWN, getpid());
	fd_flags      = fcntl (0, F_GETFL);
	fcntl (0, F_SETFL, (fd_flags | O_ASYNC));
}
