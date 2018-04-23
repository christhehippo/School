///////////////////////////////////////////////////////
//		0x1_kernal_...
//
//  a program to show understanding of kernal signals
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalCatcher(int signum);
void signore();

int main()
{
	signal(SIGINT, signalCatcher);	
	
	while(1)
	{
		fprintf(stdout, "Send me a SIGINT.\n");
		sleep(5);
	}

	return(0);
}

void signalCatcher(int signum)
{
	if (signum == SIGINT)
	{
		fprintf(stdout, "Got SIGINT\n");
		signore();
	}
}

void signore()
{
	char c;
	signal(SIGINT, SIG_IGN);
	fprintf(stdout, "\nSIGINT disabled  -  Press q then enter to quit\n\n");
//	noecho();
	while (1)
	{
		c = getchar();
		if (c == 'q')
			break;
		else
			fprintf(stdout, "Wrong key");
		
		sleep(3);
	}
	
	exit(0);
}
