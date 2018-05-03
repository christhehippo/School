#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

#define TIME_MEM_KEY 99
#define SEG_SIZE	 ((size_t)100)
#define oops(m,x) { perror(m); exit(x); }

int main ()
{
	int   seg_id    = 0;
	char *mem_ptr  = NULL;
	long  now 		= 0;
	int   n			= 0;
	

	seg_id			= shmget(TIME_MEM_KEY, SEG_SIZE, IPC_CREAT|0777);
	if (seg_id	   == -1)
		oops("shmget", 1);

	mem_ptr			= shmat(seg_id, NULL, 0);
	if (mem_ptr    == (void*) -1)
		oops("shmat", 2);

	for (n = 0; n < 60; n++)	
	{
		time(&now);
		strcpy(mem_ptr, ctime(&now));
		sleep (1);
	}

	shmctl(seg_id, IPC_RMID, NULL);

	return(0);
}
