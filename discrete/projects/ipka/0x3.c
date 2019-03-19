#include <stdio.h>
#include <stdlib.h>

char ging(char acter, char ade);

void printbin(char latan);

int main(int argc, char **argv)
{
	char  a   = atoi(argv[1]);
	char  b   = atoi(argv[2]);
	char  c   = ging(a, b);
	
	printbin(c);
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

void printbin(char latan)
{
	int   i    = 0;
	char *bin  = malloc(sizeof(char) * 8);
	for (i     = 0; i < 8; i++)
		bin[i] = 48;
	char  tmp  = 0;
	char  c	   = latan;

	tmp = 1 & c;
	if (tmp == 1)
		bin[7] = 49;
	tmp = 2 & c;
	if (tmp == 2)
		bin[6] = 49;
	tmp = 4 & c;
	if (tmp == 4)
		bin[5] = 49;
	tmp = 8 & c;
	if (tmp == 8)
		bin[4] = 49;
	tmp = 16 & c;
	if (tmp == 16)
		bin[3] = 49;
	tmp = 32 & c;
	if (tmp == 32)
		bin[2] = 49;
	tmp = 64 & c;
	if (tmp == 64)
		bin[1] = 49;
	tmp = 128 & c;
	if (tmp == 128)
		bin[0] = 49;

	fprintf(stdout, "%s\n", bin);


}
