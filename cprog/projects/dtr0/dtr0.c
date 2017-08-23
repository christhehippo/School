/*
* dtr0.c - A program to derive and display information
*		   for the signed and unsigned data types in C
*
*
* A program by Christian Cattell for CSCS1320 C/C++ Programming  Fall2017
*
* Compile with: gcc -o dtr0 dtr0.c
* Execute with: ./dtr0
*/

#include <stdio.h>

int main ()
{
	// Variables
	unsigned char 		uchr = 0;
	signed char   		schr = 0;
	//unsigned short int  usint = 0;
	//signed short int    ssint = 0;
	//unsigned int        uint = 0;
	//signed int          sint = 0;
	//unsigned long int   ulint = 0;
	//signed long int     slint = 0;
	//unsigned long long  ullint = 0;
	//signed long long    sllint = 0;

	// Code for unsigned char
	fprintf(stdout, "TYPE: %13s, " , "unsigned char");
	fprintf(stdout, "bytes: %lu, ", sizeof(uchr));
	fprintf(stdout, "low: %hhu, ",  (uchr & 0x00));
	fprintf(stdout, "high: %hhu, ", (uchr | 0xFF));
	uchr = uchr - 1;
	fprintf(stdout, "qty: %hu\n",   (uchr+1));
	
	// Code for signed char
	fprintf(stdout, "TYPE: %11s, ", "  signed char");
	fprintf(stdout, "bytes: %lu, ", sizeof(schr));
	fprintf(stdout, "low: %hhd, ", (schr | 0x80)); 
	fprintf(stdout, "high: %hhd, ", (schr | 0x7F));
	schr = schr - 1;
	fprintf(stdout,"qty: %hhd\n",    (schr+1));
	// Code for unsigned short int

	// Code for signed short int

	// Code for unsigned int

	// Code for signed int

	// Code for unsigned long int

	// Code for signed long int

	// Code for unsigned long long int

	// Code for signed long long int

	return(0);
}

