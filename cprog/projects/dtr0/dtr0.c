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
	unsigned short int  usint = 0;
	signed short int    ssint = 0;
	unsigned int        uint = 0;
	signed int          sint = 0;
	unsigned long int   ulint = 0;
	signed long int     slint = 0;
	unsigned long long  ullint = 0;
	signed long long    sllint = 0;

	// Code for unsigned char
	fprintf(stdout, "TYPE: %13s, ", "unsigned char");
	fprintf(stdout, "bytes: %lu, ", sizeof(uchr));
	//line below sets all bits to 0
	fprintf(stdout, "low: %hhu, ",  (uchr & 0x00));
	//line below sets all bits to 1
	fprintf(stdout, "high: %hhu, ", (uchr | 0xFF));
	uchr = uchr - 1;
	//changing from hhu to hu, as hhu can display only to 255 (?)
	fprintf(stdout, "qty: %hu\n",   (uchr+1));
	
	// Code for signed char
	fprintf(stdout, "TYPE: %11s, ", "  signed char");
	fprintf(stdout, "bytes: %lu, ", sizeof(schr));
	fprintf(stdout, "low: %hhd, ", (schr | 0x80)); 
	fprintf(stdout, "high: %hhd, ", (schr | 0x7F));
	fprintf(stdout,"qty: %hu\n",    (uchr+1));
	
	// Code for unsigned short int
	fprintf(stdout, "TYPE: %18s, ", "unsigned short int");
	fprintf(stdout, "bytes: %lu, ", sizeof(usint));
	fprintf(stdout, "low: %hu, ", (usint & 0x00));
	fprintf(stdout, "high: %hu, ", (usint | 0xFFFF));
	usint = usint - 1;
	fprintf(stdout, "qty: %u\n", (usint+1));
	
	// Code for signed short int
	fprintf(stdout, "TYPE: %18s, ", "signed short int");
	fprintf(stdout, "bytes: %lu, ", sizeof(ssint));
	fprintf(stdout, "low: %hd, ", (ssint | 0x8000));
	fprintf(stdout, "high: %hd, ", (ssint | 0x7FFF));
	fprintf(stdout, "qty: %u\n", (usint+1));
	
	// Code for unsigned int
	fprintf(stdout, "TYPE: %12s, ", "unsigned int");
	fprintf(stdout, "bytes: %lu, ", sizeof(uint));
	fprintf(stdout, "low: %u, ", (uint & 0x00000000));
	//Something got odd around here and Im not 100% sure why but
	//I fixed it as far as I can tell.
	fprintf(stdout, "high: %u, ", (uint | 0xFFFFFFFE));
	uint = uint -1;
	fprintf(stdout, "qty: %lu\n", (uint));
	
	// Code for signed int
	fprintf(stdout, "TYPE: %12s, ", "signed int");
	fprintf(stdout, "bytes: %lu, ", sizeof(sint));
	fprintf(stdout, "low: %d, ", (sint | 0x80000000));
	fprintf(stdout, "high: %d, ", (sint | 0x7FFFFFFF));
	fprintf(stdout, "qty: %lu\n", (uint));
	
	// Code for unsigned long int
	fprintf(stdout, "TYPE: %17s, ", "unsigned long int");
	fprintf(stdout, "bytes: %lu, ", sizeof(ulint));
	fprintf(stdout, "low: %lu, ", (ulint & 0x00));
	fprintf(stdout, "high: %lu, ", (ulint | 0xFFFFFFFFFFFFFFFE));	
	ulint = ulint -1;
	fprintf(stdout, "qty: %llu\n", (ulint));

	// Code for signed long int
	fprintf(stdout, "TYPE: %17s, ", "signed long int");
	fprintf(stdout, "bytes: %lu, ", sizeof(slint));
	fprintf(stdout, "low: %ld, ", (slint | 0x8000000000000000));
	fprintf(stdout, "high: %ld, ", (slint | 0x7FFFFFFFFFFFFFFF));
	fprintf(stdout, "qty: %llu\n", (ulint));
	
	// Code for unsigned long long int
	fprintf(stdout, "TYPE: %22s, ", "unsigned long long int");
	fprintf(stdout, "bytes: %lu, ", sizeof(ullint));
	fprintf(stdout, "low: %llu, ", (ullint & 0x00));
	fprintf(stdout, "high: %llu, ", (ullint | 0xFFFFFFFFFFFFFFFE));
	ullint = ullint -1;
	fprintf(stdout, "qty: %llu\n", (ullint));

	// Code for signed long long int
	fprintf(stdout, "TYPE: %22s, ", "signed long long int");
	fprintf(stdout, "bytes: %lu, ", sizeof(sllint));
	fprintf(stdout, "low: %lld, ", (sllint | 0x8000000000000000));
	fprintf(stdout, "high: %lld, ", (sllint | 0x7FFFFFFFFFFFFFFF));
	fprintf(stdout, "qty: %llu\n", (ullint));

	return(0);
}

