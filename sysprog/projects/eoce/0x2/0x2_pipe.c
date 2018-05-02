//////////////////////////////////////////
// 		0x3_pipe
//  a program to show understanding of c pipes
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main ()
{
	int    fd[2];    // pipe() takes a pointer to two element array
	pid_t  childpid;
	char  *msg       = "This is being sent through a pipe.\n";
	char  msgGetter[256];
	pipe(fd);

	if ((childpid = fork()) == -1)
	{
		perror("");
		exit(1);
	}

	if (childpid == 0)
	{
		fprintf(stdout, "I am a child, I am sending this through a pipe to my parent: %s", msg);
		close(fd[0]);  // closing the input side of the pipe
		write(fd[1], msg, strlen(msg) + 1);  // write to input end of pipe
		exit(0);								// msg, buffer size of msg + 1
		// end child's life
	}
	else
	{
		close(fd[1]); // close output end of pipe
		read(fd[0], msgGetter, sizeof(msgGetter)); // read the data from f[0]
												   // which is the data from f[1]
		fprintf(stdout, "I am a parent, my child sent me this through his/her pipe: %s", msgGetter);
	}

	return(0);
}
