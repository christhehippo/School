/////////////////////////////////////////
//		0x3_rm.c
//	program to replicate rm function
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc < 2)	// check arg count
	{
		fprintf(stderr, "Please provide a file or directory to remove.\n");
		exit(1);
	}

	int index  = 1;
	char *path = argv[1];  // first path initialized 
	char c     = 'n';      // store y/n for delete choice
	char junk  = 0;
	struct stat st;

	strcpy (path, argv[1]);


	while(path != NULL)
	{
		c = 'n';  // get rid of y in case something goes wrong 

		chdir(".");
		stat(path, &st);	// fill stat struct, we will check st_mode
		
		if (st.st_mode == 33188)	// check if this is a regular file
		{
			fprintf(stdout, "rm: remove regular file '%s'? ", path);
			fscanf (stdin, "%c%c", &c, &junk);
			
			if (c == 'y')	// make sure you are sure about this
			{
				if (unlink(path) == -1)
				{
					perror("unlink error");
				}
			}
		}
		else if (st.st_mode == 16877)  // check if this is a dir
		{
			fprintf(stdout, "rm: remove directory '%s'? ", path);
			fscanf (stdin, "%c%c", &c, &junk);
			
			if (c == 'y')	// make sure you are sure about this
			{
				if (rmdir(path) == -1)
				{
					perror("rmdir error");
				}
			}

		}
		else 
		{
			fprintf(stderr, "ERROR: %s is an incompatable file type\n", path);
		}

		index++;
		path = argv[index];
	}

	return(0);
}
