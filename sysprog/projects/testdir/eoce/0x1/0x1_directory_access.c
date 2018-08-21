//////////////////////////////////////////////////////////
//		0x1_directory_access 
// program to demonstate understanding of directory access
//

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	
	char *path = NULL;		// path to be ls'd
	if (argc == 1)
	{
		path = "."; 		// if no given arg, use pwd
	}
	else
	{
		path = argv[1];		// else use given dir
	}

	DIR *dir = opendir(path);		// open the directory 
	struct dirent *dirStruct = NULL;


	if (dir == NULL)				// error handling 
	{
		perror("");				
		closedir(dir);
		exit(2);
	}

	while ((dirStruct = readdir(dir)) != NULL)
	{
		fprintf(stdout, "%s\n", dirStruct -> d_name); // print until readdir is null

	}
	




	closedir(dir);			// close the dir
	return(0);
}
