////////////////////////////////////////////////////
//		0x1_file_permissions
// program to show understanding of file permissions
//    - pretty much just a chmod c program 
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main (int argc, char **argv)
{
	if (argc < 2)				// error no file
	{
		fprintf(stderr, "No file provided.\n");
		return(1);
	}
	if (argc < 3)
	{
		fprintf(stderr, "No permissions provided.\n");
		return(2);
	}

	int octPerm = strtol(argv[2], 0, 8);	  // convert the argument to octal value
	int val     =  chmod(argv[1], octPerm);   // chmod the file provided
	


	if (val == -1)							  // error stuff I guess
	{
		perror("fchmod");
		exit(3);
	}


	return(0);
}
