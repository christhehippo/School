#include <stdio.h>
#include <stdlib.h>

FILE *popen2 (const char *, const char *);

int main()
{
	FILE *fp = NULL;

	fp = popen2 ("cat", "w");
	fprintf (fp, "where does this show up?\n");
	pclose (fp);

	return (0);
}
