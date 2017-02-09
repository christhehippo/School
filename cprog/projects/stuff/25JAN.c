#include <stdio.h>
#include <stdlib.h>


int main()
{

	signed char a = 65;
	unsigned char b = 201;
	signed short int c = -2047;
	unsigned int d = 132072; 
	signed long int e = -20123456789;
	float f = 3.14;


	fprintf(stdout, "a is: %hhd '%c'\n", a, a);
	fprintf(stdout, "b is: %hhu, c is: %hd\n", b, c);
	fprintf(stdout, "%-4.3hhd, %8.3f\n", a, f);
	fprintf(stdout, "%5hhu, %.5hhd\n", b, a);






	return (0);

}
