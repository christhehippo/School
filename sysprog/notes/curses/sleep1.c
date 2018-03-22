#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main ()
{
	void wakeup (int);
	int x;

	fprintf (stdout, "about to sleep for 4 seconds\n");
	signal (SIGALRM, wakeup);
	alarm (4);
	for (x = 0; x < 8; x++)
	{
		fprintf (stdout, "in the loop\n");
		usleep (60000);
	}
	fprintf (stdout, "now paused\n");
	pause ();
	fprintf (stdout, "Morning so soon?\n");
	
	return (0);
}

void wakeup (int signum)
{
#ifndef SHHHH
	fprintf (stdout, "Alarm recieved from kernal\n");
#endif
}
