#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM 5

void *print_msg(void *);

int main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, (void *)print_msg, (void *)"Hello, ");
	pthread_create(&t2, NULL, (void *)print_msg, (void *)"World!\n");


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	
	return(0);
}

void *print_msg(void *data)
{
	int index = 0;
	char *message = (char *)data;	
	for (index = 0; index < NUM; index++)
	{
		fprintf(stdout, "%s", message);
		fflush (stdout);

		sleep(1);
	}
	return (NULL);
}
