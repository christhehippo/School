#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = NULL;

	fp = popen ("ls -a", "r");
	fprintf (fp, "where does this show up?\n");
	pclose (fp);

	return (0);
}
