//////////////////////////////////////////////////////////
/// binary.c - program to display hex numbers in their
///            binary representation.
///
///  synopsis: binary [OPTION]... [FILE]...
///
///   execute: binary -s "de ad be ef 00 01 5a"
///        or: echo "de ad be ef 00 01 5a" | binary


///////
////// Mistakes were made
//////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

#define  VERSION "0.01"

#define  YES     1
#define  NO      0

void usage   (char *);
void version (char *);
void decimal_to_binary_normal(char *string, char *delim, int digits, FILE *output);
void hex_to_binary_normal (char *string, char *delim, int digits, FILE *output);

int main (int argc, char **argv)
{
	FILE *output  		= stdout;
	FILE *empty   		= NULL;
	int opt				= 0;
	int option_index    = 0;
	int string_flag 	= NO;
	int four_flag 		= NO;
	int seven_flag 		= NO;
	int eight_flag 	  	= YES;
	int digits          = 8;
	int no_delim_flag 	= NO;
	int set_delim_flag 	= NO;
	int quiet_flag 		= NO;
	int verbose_flag 	= NO;
	int binary_flag		= NO;
	int octal_flag 		= NO;
	int decimal_flag	= NO;
	int hex_flag 		= YES;
	char *delim 		= NULL;       
	char string[250];	   			
	
//	FILE *fp;

	static struct option long_options[] = {
		{ "help", 	 no_argument,       0, 'h' },
		{ "version", no_argument,       0, 'V' },
		{ "string",  required_argument, 0, 's' },
		{ "four",    no_argument, 		0, '4' },
		{ "seven",   no_argument, 		0, '7' },
		{ "eight",   no_argument, 		0, '8' },
		{ "nodelim", no_argument, 		0, 'n' },
		{ "delim",   required_argument, 0, 'd' },
		{ "quiet",   no_argument,       0, 'q' },
		{ "verbose", no_argument,		0, 'v' },
		{ "binary",  no_argument, 		0, 'B' },
		{ "octal",   no_argument,  		0, 'O' },
		{ "decimal", no_argument,		0, 'D' },
		{ "hex",	 no_argument,		0, 'H' },
		{ "file",    required_argument, 0, 'f' },
		{ 0,	     0,					0,  0  }
	};


	while ((opt = getopt_long (argc, argv, "hVs:478nd:qvBODHf", long_options, &option_index)) != -1)
	{	
		switch(opt)
		{
			case 'h':
				usage (argv[0]);
				exit (0);
			case 'V':
				version (argv[0]);
				exit (0);
			case 's':
				string_flag = YES;
				strcpy(string, optarg);
//				string = strdup(optarg);
//				printf("%s", string);
				break;
			case '4':
				digits = 4;
				four_flag  = YES;
				seven_flag = NO;
				eight_flag = NO;
				break;
			case '7':
				digits = 7;
				four_flag  = NO;
				seven_flag = YES;
				eight_flag = NO;
				break;
			case '8':	
				digits = 8;
				four_flag  = NO;
				seven_flag = NO;
				eight_flag = YES;
				break;
			case 'n':
				no_delim_flag = NO;
				break;
			case 'd':
				set_delim_flag = YES;
				delim = strdup(optarg);
				break;
			case 'q':
				quiet_flag = YES;
				break;
			case 'v':
				verbose_flag = YES;
				break;
			case 'B':
				binary_flag = YES;
				break;
			case 'O':
				octal_flag = YES;
				break;
			case 'D':
				decimal_flag = YES;
				break;
			case 'H':
				hex_flag = YES;
				break;
			case 'f':
				break;
			default:
				break;
		}
	}
/////////////////////////////////////////////////////		


//	char se;

//	int i = 0;
//	while (string[i] != '\0')
//	{	
//		sep = strtok(string, delim); 
//
//	}













//	if (hex_flag == YES)
//	{
//		if (quiet_flag == YES)
//		{
//			output = stderr;
			hex_to_binary_normal(string, delim, digits, output);
/*		}
		else if (verbose_flag == YES)
		{
			fprintf(stdout, "Printing %s as binary with %hhu digits and using '%s' as the delimeter.\n", string, digits, delim);
			hex_to_binary_normal(string, delim, digits, output);
		}
		else
		{
			hex_to_binary_normal(string, delim, digits, output);
		}
	}
	else if (decimal_flag == YES)
	{
		if (quiet_flag == YES)
		{
			output = stderr;
			decimal_to_binary_normal(string, delim, digits, output);
		}
		else if (verbose_flag == YES)
		{
			fprintf(stdout, "Printing %s as binary with %hhu digits and using '%s' as the delimeter.\n", string, digits, delim);
			decimal_to_binary_normal(string, delim, digits, output);
		}
		else
		{
			decimal_to_binary_normal(string, delim, digits, output);
		}
	}


*/

	return (0);
}

void usage (char *name)
{

}

void version (char *name)
{

}

void decimal_to_binary_normal(char *string, char *delim, int digits, FILE *output)
{


}

void hex_to_binary_normal(char *string, char *delim, int digits, FILE *output)
{
	int i = 0;
	int digitTrim = 3;
	while(string[i] != '\0')
	{
		if (string[i] == ' ')
			if (delim == NULL)
				fprintf(stdout, " ");
			else
				fprintf(stdout, "%s", delim);	
		else
		{
			switch(string[i])
			{
			 case '0': printf("0000"); break;
             case '1': printf("0001"); break;
             case '2': printf("0010"); break;
             case '3': printf("0011"); break;
             case '4': printf("0100"); break;
             case '5': printf("0101"); break;
             case '6': printf("0110"); break;
             case '7': printf("0111"); break;
             case '8': printf("1000"); break;
             case '9': printf("1001"); break;
             case 'A': printf("1010"); break;
             case 'B': printf("1011"); break;
             case 'C': printf("1100"); break;
             case 'D': printf("1101"); break;
             case 'E': printf("1110"); break;
             case 'F': printf("1111"); break;
             case 'a': printf("1010"); break;
             case 'b': printf("1011"); break;
             case 'c': printf("1100"); break;
             case 'd': printf("1101"); break;
             case 'e': printf("1110"); break;
             case 'f': printf("1111"); break;	
			}
		}
		i++;
	}
}
