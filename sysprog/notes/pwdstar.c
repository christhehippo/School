#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char pwd[30];  					
	struct termios info_old;
	struct termios info_new;
	int rv;
	int index = 0;
	rv =  tcgetattr(0, &info_old);
	memcpy (&info_new, &info_old, sizeof(struct termios));
	info_new.c_lflag &= ~ICANON;
	info_new.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &info_new);
	
	fprintf(stdout, "Password: ");	
	
	while ((fscanf(stdin, "%c", &pwd[index])) != '\0')	// Collect input
	{													// 1 at a time
		if (pwd[index] == '\n')
			break;

		index++;
		fprintf(stdout, "*"); 							// Print * each time
	}
	fprintf(stdout, "\n");

//	info.c_lflag &= ICANON;
//	info.c_lflag &= ECHO;
	tcsetattr(0, TCSANOW, &info_old);
	
	index = 0;
	while (pwd[index] != '\0')
	{
		fprintf(stdout, "pwd[%d]: %c\n", index, pwd[index]);
		index++;
	}
	
	return (0);
}
