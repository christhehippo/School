#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

struct highlight
{
	long address;
	int  length;
};

int main(int argc, char **argv)
{
	
////// File operations///////////////////////////////////////////
	if (argc < 2)
	{
		fprintf(stderr, "%s: no file provided.\n", argv[0]);
		exit(1);
	}

	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Could not open '%s' for reading!\n", argv[1]);
		exit(2);
	}
/////////////////////////////////////////////////////////////////
/////Check window size///////////////////////////////////////////
	struct winsize terminal;
	ioctl  (0, TIOCGWINSZ, &terminal);
	
	if (terminal.ws_col < 80)
	{
		fprintf(stderr, "Error: Terminal width is less than 80 columns!\n");
		exit (3);
	}
	else if (terminal.ws_row < 20)
	{
		fprintf(stderr, "Error: Terminal height is less than 20 lines!\n");
		exit (4);
	}
/////////////////////////////////////////////////////////////////	

	int throttle = 0;
	struct highlight *hl = malloc(sizeof(struct highlight) * ((argc - 2) / 2));
	
	if (argc    == 3)
		throttle = atoi(argv[2]);
	
	if (argc >= 5)
	{
		

	}
/////////////////////////////////////////////////////////////////
/////////Vars///////////////////////////////////////////////////	
	char *c		   = (char *) malloc(sizeof(char) * 16);
	int index 	   = 0;
	int space      = 0;
	int address    = 0;
	int lineCount  = 0;

////////////////////////////////////////////////////////////////
///////Stange Logic/////////////////////////////////////////////
	while ((c[index] = fgetc(fp)) != EOF)
	{
		if (index == 0)
		{
			lineCount++;
			fprintf(stdout, "%08x: ", address);
		}
		else if (index == 15)
		{
			for (index = 0; index < 16; index++)
			{
				space++; // space ticker
				address++; // keep track of the address we are at
				fprintf(stdout, "%02x", (unsigned char)c[index]); // hex output
				
				if (space == 2)
				{
					fprintf(stdout, " ");
					space = 0;
				}
			}
			fprintf(stdout, " "); // pad a space between outputs
			for (index = 0; index < 16; index++)
			{
				if (c[index] > 32) // ascii output
					fprintf(stdout, "%c", c[index]);
				else
					fprintf(stdout, ".");
			}
			fprintf(stdout, "\n");
			index = -1;
			
			if (lineCount == throttle)
			{
				return (0);
			}
		}
		index++;
	}
	
	index = 0;
	// print whatever is leftover from the prior loop
	while (c[index] != EOF)
	{
		space++; // space ticker
		address++;
		fprintf(stdout, "%02x", c[index]);
		
		if (space == 2)
		{
			fprintf(stdout, " ");
			space = 0;
		}
		index++;
	}

	if (index % 2 == 0)
	{
		fprintf(stdout, " ");
	}
	else
	{
		fprintf(stdout, "   ");
		index++;
	}
	space = 0;
	while (index < 16)
	{
		space++;
		fprintf(stdout, "  ");
		if (space == 2)
		{
			fprintf(stdout, " ");
			space = 0;
		}
		index++;
	}
	fprintf(stdout, " "); // I am missing something about this logic
	index = 0;			  //  which is making me need lots of these band aids

	while (c[index] != EOF)
	{
		if (c[index] > 20)
			fprintf(stdout, "%c", c[index]);
		else
			fprintf(stdout, ".");
		index++;
	}
	fprintf(stdout, "\n");

	free(c);
	free(hl);
	fclose(fp);
	return(0);
}
