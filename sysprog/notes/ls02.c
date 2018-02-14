#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/time.h>
#include <time.h>

void do_ls (char *, char *);

int main (int argc, char **argv)
{
	int index = 1;
	if (argc == 1)
	{
		do_ls( argv[0], ".");
	}
	else
	{
		while (--argc)
		{
//			fprintf (stdout, "%s:\n", *++argv);
			do_ls (argv[0], argv[index]);
			index++;
		}
	}

	return (0);
}

void do_ls (char *argv0, char *dirname)
{
	char 		  *stroftime;
	DIR 		  *dptr		 = NULL;
	struct dirent *dirp 	 = NULL;
	struct stat   *file 	 = NULL;
	unsigned short int type  = 0;
	unsigned short int perm  = 0;
	unsigned short int value = 0;
	signed short int shift   = 6; // shift happens
	unsigned short int mask  = 00007;
	struct passwd   *user	 = NULL;
	struct group    *grupo   = NULL;
	struct tm		*mytime  = NULL;

	file 				= (struct stat *) malloc (sizeof (struct stat));
	stroftime			= (char *) malloc (sizeof (char) * 80);

	if ((dptr = opendir (dirname)) == NULL)
	{
		fprintf (stderr, "%s: cannot open %s\n", argv0, dirname);
	}
	else
	{
		chdir(dirname);
		while((dirp = readdir (dptr)) != NULL)
		{
			stat (dirp -> d_name, file);
			type	   = (file -> st_mode) >> 12;
			perm       = (file -> st_mode) & 0007777;
			if (type == 010)
				fprintf (stdout, "-");
			else if (type == 4)
				fprintf (stdout, "d");

			shift = 6;
			while (shift >= 0)
			{
				value = perm;
				value = value >> shift;
				value = value & mask;
				
				if ((value & 4) == 4)
					fprintf (stdout, "r");
				else
					fprintf(stdout, "-");
			
				if ((value & 2) == 2)
					fprintf(stdout, "w");
				else
					fprintf (stdout, "-");

				if ((value & 1) == 1)
					fprintf(stdout, "x");
				else
					fprintf (stdout, "-");


				shift-= 3;					
			}

			fprintf (stdout, " %ld ", file -> st_nlink);
			user  = getpwuid  (file -> st_uid);
			grupo = getgrgid  (file -> st_gid);
			fprintf (stdout, " %s", user   -> pw_name);
			fprintf (stdout, " %s", grupo  -> gr_name);
			fprintf (stdout, " %lu", file  -> st_size);

			mytime = localtime(&(file -> st_mtime)); 
			strftime (stroftime, 20, "%b %d, %H ", mytime);
			fprintf (stdout, " %s", stroftime);
			fprintf (stdout, " %s\n", dirp -> d_name);		
		}
		closedir (dptr);
	}
}








