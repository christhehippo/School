//////////////////////////////////////////////////////////
/// binary.c - program to display hex numbers in their
///            binary representation.
///
///  synopsis: binary [OPTION]... [FILE]...
///
///   execute: binary -s "de ad be ef 00 01 5a"
///        or: echo "de ad be ef 00 01 5a" | binary


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>


#define  YES     1
#define  NO      0

void usage      (char *);
void version    (char *);
void outputF	(long, char *, int, FILE *); 

////////////////Vars/////////////////////////////////////
int main (int argc, char **argv)
{
	FILE *output  		= stdout;
//	FILE *empty   		= NULL;
	int opt				= 0;
	int option_index    = 0;
	int digits          = 8;
	int verbose_flag 	= NO;
	int quiet_flag		= NO;
	int binary_flag		= NO;
	int octal_flag 		= NO;
	int decimal_flag	= NO;
	int hex_flag 		= YES;
	int str_flag        = NO;
	char *delim 		= " ";       
	char string[250];	   			
	long convTok[250];
	char space[2] 		= " ";
	char *token;
	char *eptr			= "\0";
	int i				= 0;

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
/////////////////////////////////////////////////////////////////////////

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
				str_flag = YES;
				strcpy(string, optarg);
				break;
			case '4':
				digits = 4;
				break;
			case '7':
				digits = 7;
				break;
			case '8':	
				digits = 8;
				break;
			case 'n':
				delim = "";
				break;
			case 'd':
				delim = strdup(optarg);
				break;
			case 'q':
				output = stderr;
				break;
			case 'v':
				verbose_flag = YES;
				break;
			case 'B':
				binary_flag  = YES;
				hex_flag 	 = NO;
				octal_flag   = NO;
				decimal_flag = NO;
				break;
			case 'O':
				octal_flag   = YES;
				binary_flag  = NO;
				hex_flag	 = NO;
				decimal_flag = NO;
				break;
			case 'D':
				decimal_flag = YES;
				binary_flag  = NO;
				hex_flag     = NO;
				octal_flag   = NO;
				break;
			case 'H':
				hex_flag 	 = YES;
				decimal_flag = NO;
				binary_flag  = NO;
				octal_flag	 = NO;
				break;
//			case 'f':
//				break;
			default:
				break;
		}
	}
/////////////////////////////////////////////////////		
	
	if (str_flag == NO) // Do some file stuff
	{
		FILE *fp = fopen(argv[argc-1], "r");
//		if (fp == NULL) //  make sure we got the file 
//		{
//		fprintf(stdout, "Please put the file after the arguements.\n");
//			return(1);
//		}
		while (fgets(string, sizeof(string), fp) != NULL)
		{
			// party
		}
		fclose(fp);

	}

	if (verbose_flag == YES) // Do some verbose stuff
	{
		if (binary_flag == YES)
			fprintf(output, "BINARY INPUT: %s\n", string);
		else if (decimal_flag == YES)
			fprintf(output, "DECIMAL INPUT: %s\n", string);
		else if (octal_flag == YES)
			fprintf(output, "OCTAL INPUT: %s\n", string);
		else
			fprintf(output, "HEX INPUT: %s\n", string);
		
		fprintf(output, "USING BYTE SIZE: %d\n", digits);
		fprintf(output, "USING DELIMETER: '%s'\n", delim);
	}
	
	if (decimal_flag == YES)
	{
		// This all got really weird with the pointers but..	
		token = strtok(string, space);
		// token points to first seperated string piece
		// Then set the converted token to a spot in the long int array using b 10
		convTok[i] = strtol(token, &eptr, 10);
		outputF(convTok[i], delim, digits, output);
		
		while (1)
		{	
			// Repeat inside this loop
			// Can't explain why I needed the first part outside the loop
			// but I have an idea as to why
			token = strtok(NULL, space);
			
			if (token == NULL)
				break; // This fixed my seg fault issue 

			convTok[i] = strtol(token, &eptr , 10); 
			outputF(convTok[i], delim, digits, output);
			i++;									
		}
		fprintf(output, "\n");
	}
	else if (octal_flag == YES) // Same as decimal process, but base 8 in strtol
	{
		token = strtok(string, space);
		convTok[i] = strtol(token, &eptr, 8);
		outputF(convTok[i], delim, digits, output);

		while (1)
		{	
			token = strtok(NULL, space);
			
			if (token == NULL)
				break;  

			convTok[i] = strtol(token, &eptr , 8); 
			outputF(convTok[i], delim, digits, output);
			i++;									
		}
		fprintf(output, "\n");
	}
	else if (hex_flag == YES)  // default case
	{
		token = strtok(string, space);
		convTok[i] = strtol(token, &eptr, 16);
		outputF(convTok[i], delim, digits, output);
		while (1)
		{	
			token = strtok(NULL, space);
			
			if (token == NULL)
				break; 
 
	 		convTok[i] = strtol(token, &eptr , 16); 
			outputF(convTok[i], delim, digits, output);
			i++;									
		}
		fprintf(output, "\n");
	}
	else if (binary_flag == YES)
	{
		if (quiet_flag == YES) // just end on quiet flag
			return (0);

		token = strtok(string, space);
		fprintf(output, "%s%s", token + strlen(token) - digits, delim);
		while (1)
		{
			token = strtok(NULL, space); // input is binary so return it with variable digits
			if (token == NULL)
				break;
			fprintf(output, "%s%s", token + strlen(token) - digits, delim);
		}
		fprintf(output, "\n");
	}
	

	return (0);
}

void usage (char *name)
{
	fprintf(stdout, "\nbinary.c - program to display hex numbers in their\n           binary representation.\n\n  synopsis: binary [OPTION]... [FILE]...\n\n   execute: %s -s \"de ad be ef 00 01 5a\"\n        or: echo \"de ad be ef 00 01 5a\" | binary\n\n", name);
	fprintf(stdout, "-h display usage information and exit\n-V display version information and exit\n-s \"STRING\" specify STRING as value to process\n-4 set nibble as processing unit/word size\n-7 set byte/word as 7-bits\n-8 set byte/word as 8-bits (default)\n-n no delimiter between processing units\n-d 'CHAR' use CHAR as delimiter between processing units (space is default)\n-q quiet, do not display anything to STDOUT\n-v verbose, display more information to STDOUT\n-B input data is to be considered as binary (basically a passthrough)\n-O input data is to be considered as octal\n-D input data is to be considered as decimal\n-H input data is to be considered as hexadecimal (default)\n\n");
}

void version (char *name)
{
	fprintf(stdout, "\n%s VERSION: 0.69\n\n", name);
}

void outputF (long ct, char *delim, int digits, FILE *output)
{
///////////Populate array that will store a bin number////
	long num       = ct;
	long div       =  0;
	long binA[8]   = {0}; // binary value goes in here	
	long index     =  7;
	while (1)
	{
		div = num % 2;  
		binA[index] = div; // Cant put into words how I did this
		num = num / 2;     // here is link for logic I used:
		index--;		   // http://www.cs.odu.edu/~jbollen/cgi-bin/dec2bin.cgi?dec=46	
		
		if (num == 0)
			break;
	}
/////////////////////////////////////////////////////
//////////digit formating////////////////////////////
	if (digits == 8)
	{
		for (index = 0; index < 8; index++) 
			fprintf(output, "%lu", binA[index]);
	}
	else if (digits == 7)
	{
		for (index = 1; index < 8; index++) 
			fprintf(output, "%lu", binA[index]);

	}
	else if (digits == 4)
	{
		for (index = 4; index < 8; index++) 
			fprintf(output, "%lu", binA[index]);
	}
	else
		fprintf(output, "something went wrong here\n");
////////////////////////////////////////////////////////////

	fprintf(output, "%s", delim);
}
