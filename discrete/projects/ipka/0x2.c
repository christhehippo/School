#include <stdio.h>
#include <stdlib.h>

char ging(char acter, char ade);

int main(int argc, char **argv)
{
	char a = atoi(argv[1]);
	char b = atoi(argv[2]);
	char c = ging(a, b);
	printf("%hhd\n", c);
}

char ging(char acter, char ade)
{
	char iot		= acter & ade;
	char isma		= acter ^ ade;

	if (iot			> 0)
	{
		acter		= iot << 1;
		ade			= isma;
		isma		= ging(acter, ade);
	}
	return (isma);
}
