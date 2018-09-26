#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   ANSI_RESET       "\x1b[0m"
#define   ANSI_BOLD		   "\x1b[1m"
#define   ANSI_FG_WHITE    "\x1b[37m"
#define   ANSI_FG_MAGENTA  "\x1b[35m"

int main(int argc, char **argv)
{
	FILE *f1 		= NULL;
	FILE *f2 		= NULL;
	int  *c1_old    = malloc(sizeof(int) * 16);
	int  *c2_old    = malloc(sizeof(int) * 16);
	int  *c1        = malloc(sizeof(int) * 16);
	int  *c2        = malloc(sizeof(int) * 16);
	int   i 		= 0;
	int   space     = 0;
	int   address   = 0;
	int   index     = 0;
	int   dif_flag  = 0;
	int   dif_tick  = 0;
    int	  dif_tick2 = 0;
	int   err_line  = 0;
	int   lineCount = 0;
	// open files
	f1 = fopen(argv[1], "r");
	if (f1 == NULL)
	{
		fprintf(stderr, "Error opening %s\n", argv[1]);
		return(1);
	}

	f2 = fopen(argv[2], "r");
	if (f2 == NULL)
	{
		fprintf(stderr, "Error opening %s\n", argv[2]);
		return(1);
	}

//	while ((c1[index] = fgetc(f1)) != EOF && ((c2[index] = fgetc(f2)) != EOF))
	while ((!feof(f1)) && (!feof(f2)))
	{	
		c1[index] = fgetc(f1);
		c2[index] = fgetc(f2);
		// check for character difference
		if (c1[index] != c2[index])
		{
			dif_flag = 1;
			err_line = address / 16;
		}
		if (index == 0)
			lineCount++;
		
		if (index == 15)	
		{
			// populate old array
			if (dif_flag == 1)
			{
				if (err_line == 0)
				{
					for (index = 0; index < 16; index++)
					{
						c1_old[index] = c1[index];
						c2_old[index] = c2[index];
					}
				}
				dif_tick+=1;
				dif_tick2+=1;
			}
			else
			{
				for (index = 0; index < 16; index++)
				{
					c1_old[index] = c1[index];
					c2_old[index] = c2[index];
				}
			}
			index = -1;
		}
		index+=1;
		address+=1;

		// PRINTERS BELOW
		// if it is time, print the first two lines
		if (dif_tick == 1 && dif_tick2 == 1)
		{
			
			// print start line
			space = 0;
			// band aid
			if (err_line == 0)
				address+=16;

			if (err_line == 0)
			{
				fprintf(stdout, ANSI_FG_WHITE);
				fprintf(stdout, ANSI_BOLD);
			}
			fprintf(stdout, "%.08x: ", address-32);
			fprintf(stdout, ANSI_RESET);
			for (i = 0; i < 16; i++)
			{
				if (c1_old[i] != c2_old[i])
					fprintf(stdout, ANSI_FG_MAGENTA);
				fprintf(stdout, "%.02x", c1_old[i]);
				fprintf(stdout, ANSI_RESET);
				space+=1;
				if (space == 2)
				{
					space = 0;
					fprintf(stdout, " ");
				}
			}
			// reset for the second file
			space = 0;
			fprintf(stdout, "| ");

			for (i = 0; i < 16; i++)
			{
				if (c1_old[i] != c2_old[i])
					fprintf(stdout, ANSI_FG_MAGENTA);
				fprintf(stdout, "%.02x", c2_old[i]);
				fprintf(stdout, ANSI_RESET);
				space+=1;
				if (space == 2)
				{
					space = 0;
					fprintf(stdout, " ");
				}
			}
			fprintf(stdout, "\n");
			
			if (err_line != 0) // check if error on first line
			{
				space = 0;
				fprintf(stdout, ANSI_FG_WHITE);
				fprintf(stdout, ANSI_BOLD);
				fprintf(stdout, "%.08x: ", address-16);
				fprintf(stdout, ANSI_RESET);
				for (i = 0; i < 16; i++)
				{
					if (c1[i] != c2[i])
						fprintf(stdout, ANSI_FG_MAGENTA);
					fprintf(stdout, "%.02x", c1[i]);
					fprintf(stdout, ANSI_RESET);
					space+=1;
					if (space == 2)
					{
						space = 0;
							fprintf(stdout, " ");
					}
				}
				// reset for the second file
				space = 0;
				fprintf(stdout, "| ");
	
				for (i = 0; i < 16; i++)
				{
					if (c1[i] != c2[i])
						fprintf(stdout, ANSI_FG_MAGENTA);
					fprintf(stdout, "%.02x", c2[i]);
					fprintf(stdout, ANSI_RESET);
					space+=1;
						if (space == 2)
					{
						space = 0;
						fprintf(stdout, " ");
					}
				}
				fprintf(stdout, "\n");
			}
			dif_tick2 = -1;
		}
		else if (dif_tick == 2)
		{
			space = 0;
			// band aid 2
			if (err_line == 0)
				address-=16;
			fprintf(stdout, "%.08x: ", address-16);
			for (i = 0; i < 16; i++)
			{
				fprintf(stdout, "%.02x", c1[i]);
				space+=1;
				if (space == 2)
				{
					space = 0;
					fprintf(stdout, " ");
				}
			}
			// reset for the second file
			space = 0;
			fprintf(stdout, "| ");

			for (i = 0; i < 16; i++)
			{
				fprintf(stdout, "%.02x", c2[i]);
				space+=1;
				if (space == 2)
				{
					space = 0;
					if (i != 15)
						fprintf(stdout, " ");
				}
			}
			fprintf(stdout, "\n");
			break;
		}	
	}
	// if the rror is at the end of the file
	if (dif_tick == 0)
	{
		space = 0;
		fprintf(stdout, "%.08x: ", (lineCount*16)-32);
		for (i = 0; i< 16; i++)
		{
			fprintf(stdout, "%.02x", c1_old[i]);
			space+=1;
			if (space == 2)
			{
				space = 0;
				fprintf(stdout, " ");
			}
		}
		fprintf(stdout, "| ");
		for (i = 0; i< 16; i++)
		{
			fprintf(stdout, "%.02x", c2_old[i]);
			space+=1;
			if (space == 2)
			{
				space = 0;
				fprintf(stdout, " ");
			}
		}
		fprintf(stdout, "\n");

		space = 0;
		fprintf(stdout, ANSI_FG_WHITE);
		fprintf(stdout, ANSI_BOLD);
		fprintf(stdout, "%.08x: ", (lineCount*16)-32);
		fprintf(stdout, ANSI_RESET);
		for (i = 0; i< 16; i++)
		{
			if (c1[i] == EOF)
			{
				while (i != 16)
				{
					space++;
					fprintf(stdout, "  ");
					i++;
					if (space == 2)
					{
						space = 0;
						fprintf(stdout, " ");
					}
				}

			}
			else
			{
				if (c1[i] != c2[i])
					fprintf(stdout, ANSI_FG_MAGENTA);
				fprintf(stdout, "%.02x", c1[i]);
				fprintf(stdout, ANSI_RESET);
				space+=1;
				if (space == 2)
				{
					space = 0;
					fprintf(stdout, " ");
				}
			}
		}
		fprintf(stdout, "| ");
		for (i = 0; i< 16; i++)
		{
			if (c2[i] == EOF)
			{
				while (i != 16)
				{
					space++;
					fprintf(stdout, "  ");
					i++;
					if (space == 2)
					{
						space = 0;
						fprintf(stdout, " ");
					}
				}

			}	
			else
			{
				if (c1[i] != c2[i])
					fprintf(stdout, ANSI_FG_MAGENTA);
				fprintf(stdout, "%.02x", c2[i]);
				fprintf(stdout, ANSI_RESET);
				space+=1;
				if (space == 2)
				{
					space = 0;
					fprintf(stdout, " ");
				}
			}	
		}
		fprintf(stdout, "\n");
	}
	
	
	
	
	fclose(f1);
	fclose(f2);
	return (0);
}
