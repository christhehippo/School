#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

#define  ANSI_RESET       "\x1b[0m"
#define  ANSI_BOLD        "\x1b[1m"
#define  ANSI_FG_WHITE    "\x1b[37m"
#define  ANSI_FG_MAGENTA  "\x1b[35m"

struct highlight
{
	int addr;
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

	int   throttle 		 = 0;
	int   count    	 	 = 0;
	int   tick           = 0;
	char *junk           = NULL;
	struct highlight *hl = NULL;
	
	if (argc % 2 != 0) // check if we have a throttle 
	{
		throttle  = atoi(argv[2]);
		count     = (argc - 3) / 2;
		hl = (struct highlight *)malloc(sizeof(struct highlight) * count);
		for (tick = 0; tick < count; tick++)
		{
			hl[tick].addr     = strtol(argv[((tick + 1) * 2) + 1], &junk, 16);
			hl[tick].length   = atoi(argv[((tick + 1) * 2) + 2]);
		}
	}
	else // if not, go this way
	{
		count     = (argc - 2) / 2;
		hl = (struct highlight *)malloc(sizeof(struct highlight) * count);
		for (tick = 0; tick < count; tick++)
		{
			hl[tick].addr     = strtol(argv[((tick + 1) * 2) + 0], &junk, 16);
			hl[tick].length   = atoi(argv[((tick + 1) * 2) + 1]);
		}

	}
/*
	for (tick = 0; tick < count; tick++)
	{
		fprintf(stdout, "\n%x\n", hl[tick].addr);
		fprintf(stdout, "%d\n\n", hl[tick].length);
	}
*/
/////////////////////////////////////////////////////////////////
/////////Vars///////////////////////////////////////////////////	
	int *c = malloc(sizeof(int) * 16);
	int index 	     = 0;
	int space        = 0;
	int address      = 0;
	int lineCount    = 0;
	int white_flag   = 0;
	int pink_flag    = 0;
	int pink_addr    = 0;
////////////////////////////////////////////////////////////////
///////Strange Logic/////////////////////////////////////////////
	while ((c[index] = fgetc(fp)) != EOF) // search for EOF
	{
		if (pink_flag == 0)
			white_flag = 0; // flag to check for address highlight
		
		if (index == 0) 
		{
			lineCount++;
			for (tick = 0; tick < count; tick++)
			{
				if (hl[tick].addr >= address && hl[tick].addr <= address + 0xf)
				{
					white_flag = 1;
					pink_flag = hl[tick].length;
					pink_addr = hl[tick].addr;
				}
			}
			if (white_flag == 1)
			{
				fprintf(stdout, ANSI_BOLD);
				fprintf(stdout, ANSI_FG_WHITE);
				fprintf(stdout, "%08x: ", address);
				fprintf(stdout, ANSI_RESET);
			}
			else 
			{
				fprintf(stdout, "%08x: ", address);

			}
		}

		else if (index == 15) // do this when the buffer is full
		{
			for (index = 0; index < 16; index++)
			{
				space++; // space ticker
				if ((address == pink_addr) && (pink_flag != 0))
				{
					fprintf(stdout, ANSI_FG_MAGENTA);
					fprintf(stdout, "%02x", c[index]);// hex output
					fprintf(stdout, ANSI_RESET);
					pink_flag--;
					pink_addr++;
				}
				else
				{
					fprintf(stdout, "%02x", c[index]);// hex output
				}

				address++;
				if (space == 2) // check for the spacing 
				{
					fprintf(stdout, " ");
					space = 0;
				}
			}
			fprintf(stdout, " "); // pad a space between outputs
			for (index = 0; index < 16; index++)
			{
				if (c[index] >= 32 && c[index] < 0x7f) // ascii output
					fprintf(stdout, "%c", c[index]);
				else
					fprintf(stdout, ".");
			}
			fprintf(stdout, "\n");
			index = -1; // toss this here to make the loop function properly
			
			if (lineCount == throttle)
			{
				return (0); // check if we hit the line limit AFTER the line prints
			}
		}
		index++;
	}
/////////////////////////////////////////////////////////////////
// Everything past here deals with wrapping up the final line of
// output, the main loop cannot handle the empty spaces

	if (index == 0) // check if the eof landed on the end of a line
	{
		return (0);
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

	if (index % 2 == 0) // figure out space compensation 
	{
		fprintf(stdout, " ");
	}
	else
	{
		fprintf(stdout, "    ");
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
	index = 0;			 

	while (c[index] != EOF) // print ascii characters
	{
		if (c[index] >= 20 && c[index] < 0x7f)
			fprintf(stdout, "%c", c[index]);
		else
			fprintf(stdout, ".");
		index++;
	}
	fprintf(stdout, "\n");
	
	// free shit
	free(hl);
	free(c);
	fclose(fp);
	return(0);
}
