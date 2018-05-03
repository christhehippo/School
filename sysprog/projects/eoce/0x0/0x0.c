/*
 * 0x0.c - sample code for use with EoCE
 *
 * To compile: gcc -o 0x0 0x0.c -lpthread
 * To execute: ./eoceprog 55 44 33 22 11 12 23 34 45 5 1 3 4 2
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *process(void *);

struct info
{
    unsigned char value;
};

FILE *fPtr;

int main(int argc, char **argv)
{
    void *process(void *); 
    unsigned char i     = 0;
    struct info data;
    pthread_t threads[argc-1];
	FILE *fp = NULL;
	char buf[2048];
    if (argc           <  2)
    {   
        printf("Please provide a list of positive unique whole numbers,\n");
        printf("of individual values ranging between 1 and 255\n");
        exit(1);
    }   

    if (argc           >  255)
    {
        printf("Please provide less than 256 arguments,\n");
        printf("of individual values ranging between 1 and 255\n");
        exit(1);
    }

    fPtr                = fopen("datafile", "w");
    if(fPtr            == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    for(i=1; i<argc; i++)
    {
        data.value      = (unsigned char)atoi(argv[i]);
        pthread_create(&threads[i-1], NULL, (void *) process, (void *) &data);
        usleep(32);
    }

    for(i=1; i<argc; i++)
	{
        pthread_join(threads[i-1], NULL);
	}

    fprintf(fPtr, "\n");
    fclose(fPtr);
	fp = fopen("datafile", "r");  // open the created file
	fgets(buf, sizeof(buf), fp);  // write the contents of the file to buf
	fprintf(stdout, "%s", buf);   // print the saved string to stdout
	fclose(fp);                   // close file
	return(0);
}

void *process(void *params)
{
    struct info *thing  = (struct info *)params;
    unsigned char data  = thing -> value;
    sleep((int)(data & 0xFF));
    fprintf(fPtr, "%hhu ", data);
    fflush(stdout);
	return(NULL);
}
