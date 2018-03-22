#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void countdown  (int);
int  set_ticker (int);

int main ()
{
	signal (SIGALRM, countdown);
	if (set_ticker (500) == -1)
	{
		perror ("set_ticker");	
	}
	else
	{
		while (1)
		{
			pause ();
			signal (SIGALRM, countdown);
		}
	}
	
	return (0);
}

void countdown (int signum)
{
	static int num  = 10;

	fprintf (stdout, "%d ..", num--);
	fflush  (stdout);

	if (num < 0)
	{
		fprintf (stdout, "DONE!\n");
		exit (0);
	}
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
