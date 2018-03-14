#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenstr (char *);
int stoi   (char *);


int main (int argc, char **argv)
{
	fprintf(stdout, "argv1 is %u chars long\n", strlen(argv[1]));
	fprintf(stdout, "argv1 is %u chars long\n", lenstr(argv[1]));
	fprintf(stdout, "atoi: %d\n", stoi (argv[1]));

	return (0);
}

int lenstr (char *string)
{
	int count = 0;
	while (string[count] != '\0')
	{
		count++;
	}
	return (count);
}

int stoi (char *string)
{	
	int place = 1;
	int index = 1;
	int value = 0;

	for (index = lenstr(string) -1; index >= 0; index--)
	{
		value = value + ((string[index] - '0') * place);	
		place = place * 10;
	}
	return (value);
}

