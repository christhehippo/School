#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// argv[0]: program name
// argv[1]: mode
// argv[2]: filename

int main(int argc, char **argv)
{
	// Get argv[1] as int
	int a = atoi(argv[1]);

	// Convert decimal into to octal by ie 7*8^2 + 4*8^1 + 2*8^0
	int b = ((a / 100) * 8 * 8);
	int c = (((a / 10) % 10) * 8);
	int d = a % 10;

	// Set mode equal to octal value of argv[1]
	mode_t mode = (b + c + d);
	
	// Set permissions
	chmod(argv[2], mode);
	return(0);
}
