#include <stdio.h>
#include <stdlib.h>






int main()
{
	char a, b, c;
	a=b=c=0;
	

	fprintf(stdout, "Enter a number: \n");
	fscanf(stdin, "%hhd", &a);
	fprintf(stdout, "Enter another number: \n");
	fscanf(stdin, "%hhd", &b);

	c = a + b;
	fprintf(stdout, "%hhd + %hhd = %hhd\n", a, b, c);






	return(0);


}
