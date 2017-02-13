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
    
	if (userInput < 100)
	{
	
		unsigned char d2 = (userInput%10);
		unsigned char d1 = ((userInput-d2) / 10);



		fprintf(stderr, "d1: %hhu\n", d1);
		fprintf(stderr, "d2: %hhu\n", d2);
		
	}
	else 
	{
	





		//fprintf(stderr, "d1: %hhu\n", d1);
		//fprintf(stderr, "d2: %hhu\n", d2);
		//fprintf(stderr, "d3: %hhu\n", d3);
	}













	//unsigned char d1 = (userInput/10);
	//unsigned char d2 = (userInput%(d1*10));

	//test tool
	/*fprintf(stderr, "userInput: %4hu\n", userInput);
	fprintf(stderr, "sum10000: %5hhu\n", sum10000);
	fprintf(stderr, "carry1000: %4hhu\n", carry1000);
	fprintf(stderr, "sum1000: %6hhu\n", sum1000);
	fprintf(stderr, "carry100: %5hhu\n", carry100);
	fprintf(stderr, "sum100: %7hhu\n", sum100);
	fprintf(stderr, "carry10: %6hhu\n", carry10);
	fprintf(stderr, "sum10: %8hhu\n", sum10);
	fprintf(stderr, "carry1: %7hhu\n", carry1);
	fprintf(stderr, "sum1: %9hhu\n", sum1);
	*/




	return (0);
}
