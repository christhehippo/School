#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void do_ls (char *, char *);

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		do_ls( argv[0], ".");
	}
	else
	{
		while (--argc)
		{
//			fprintf (stdout, "%s:\n", *++argv);
			do_ls (argv[0], *argv);
		}
	}

	return (0);
}

void do_ls (char *argv0, char *dirname)
{
	DIR 		  *dptr		= NULL;
	struct dirent *dirp 	= NULL;
	struct stat   *file 	= NULL;
	unsigned short int type = 0;
	unsigned short int perm = 0;


	file 				= (struct stat *) malloc (sizeof (struct stat));

	if ((dptr = opendir (dirname)) == NULL)
	{
		fprintf (stderr, "%s: cannot open %s\n", argv0, dirname);
	}
	else
	{
		while((dirp = readdir (dptr)) != NULL)
		{
			stat (dirp -> d_name, file);
			type	   = (file -> st_mode) >> 12;
			perm       = (file -> st_mode) & 0007777;
			if (type == 010)
				fprintf (stdout, "-");
			else if (type == 4)
				fprintf (stdout, "d");

			fprintf (stdout, "%o ", file -> st_mode);
			fprintf (stdout, "%s\n", dirp -> d_name);		

		}
		closedir (dptr);
	}
}








