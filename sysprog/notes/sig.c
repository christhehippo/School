#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main ()
{
	void handler(int);
	int  i;

	signal (SIGINT, handler);
	signal (SIGSEGV, SIG_IGN);
	for (i = 0; i < 10; i++)
	{
		fprintf(stdout, "hello\n");
		sleep(1);
	}
	return (0);
}

void handler(int signum)
{
	fprintf(stdout, "haha\n");
	signal(SIGINT, handler);
}
