#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int    len    = 0;
	int    index  = 0;
	int    apipe[2];
	char   buf[BUFSIZ];

	if (pipe (apipe) == -1)
	{
		perror ("pipe make we could not");
		exit (1);
	}

	fprintf (stdout, "Got pipe! It is file descriptors %d and %d\n",
					 apipe[0], apipe[1]);

	while (fgets (buf, BUFSIZ, stdin))
	{
		// write user input into pipe
		len     = strlen (buf);
		if (write (apipe[1], buf, len) != len)
		{
			perror ("pipe writing to we are not");
			break;
		}

		// erase user input
		for (index = 0; index < len; index++)
		{
			buf[index] = 'X';
		}

		// read data from pipe
		len     = read (apipe[0], buf, BUFSIZ);
		if (len  == -1)
		{
			perror ("pipe reading from we are not");
			break;
		}

		// write data to STDOUT
		if (write (1, buf, len) != len)
		{
			perror ("to stdout writing we are not");
			break;
		}
	}
	return (0);
}
