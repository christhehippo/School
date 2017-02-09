#include <stdio.h>
#include <stdlib.h>

int main ()
{

	unsigned int userInput;
	unsigned char sum10000;
	unsigned char carry1000;
	unsigned char sum1000;
	unsigned char carry100;
	unsigned char sum100;
	unsigned char carry10;
	unsigned char sum10;
	unsigned char carry1;
	unsigned char sum1;
	 
	


	fprintf(stderr, "Enter value: ");
	fscanf(stdin, "%hu", &userInput);









	//test tool
	fprintf(stderr, "userInput: %3hu\n", userInput);
	fprintf(stderr, "sum10000: %4hhu\n", sum10000);
	fprintf(stderr, "carry1000: %3hhu\n", carry1000);
	fprintf(stderr, "sum1000: %5hhu\n", sum1000);
	fprintf(stderr, "carry100: %4hhu\n", carry100);
	fprintf(stderr, "sum100: %6hhu\n", sum100);
	fprintf(stderr, "carry10: %5hhu\n", carry10);
	fprintf(stderr, "sum10: %7hhu\n", sum10);
	fprintf(stderr, "carry1: %6hhu\n", carry1);
	fprintf(stderr, "sum1: %8hhu\n", sum1);

	return (0);
}
