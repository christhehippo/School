#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

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
			fprintf (stdout, "%s:\n", *++argv);
			do_ls (argv[0], *argv);
		}
	}

	return (0);
}

void do_ls (char *argv0, char *dirname)
{
	DIR 		  *dptr	= NULL;
	struct dirent *dirp = NULL;

	if ((dptr = opendir (dirname)) == NULL)
	{
		fprintf (stderr, "%s: cannot open %s\n", argv0, dirname);
	}
	else
	{
		while((dirp = readdir (dptr)) != NULL)
		{
			fprintf (stdout, "%s\n", dirp -> d_name);		
		}
		closedir (dptr);
	}
}








