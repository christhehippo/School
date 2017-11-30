#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// argv[0]: program name
// argv[1]: mode
// argv[2]: filename

int main(int argc, char **argv)
{
	mode_t mode; // essentially an integer value

	chmod(argv[2], mode);
	return(0);
}
