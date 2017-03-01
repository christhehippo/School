#include <stdio.h>
#include <stdlib.h>

int f1(int);
int f2(int, int *);
void f3(int *, int *);

int main()
{
	int x = 73;
	int y = 13;
	
	fprintf(stdout, "main before is: x is: %d, y is: %d\n", x, y);
	f1(x);
	fprintf(stdout, "main after is: x is: %d, y is: %d\n", x, y);
	
	fprintf(stdout, "main before is: x is: %d, y is: %d\n", x, y);
	f2(x, &y);
	fprintf(stdout, "main after is: x is: %d, y is: %d\n", x, y);
	
	fprintf(stdout, "main before is: x is: %d, y is: %d\n", x, y);
	f3(&x, &y);
	fprintf(stdout, "main after is: x is: %d, y is: %d\n", x, y);
	

	
	
	return (0);
}

int f1(int x)
{
	fprintf(stdout, "f1 before is:x is: %d\n", x);
	x = x * 7;
	fprintf(stdout, "f1 after is: x is: %d\n", x);
	return(x);
}

int f2(int x, int *y)
{
	fprintf(stdout, "f2 before is: x is: %\n", x, *y);
	x = x * 7;
	*y = *y * 23;
	fprintf(stdout, "f2 after is: x is: %d\n", x, *y);
	return(x);
}

void f3(int *x, int *y)
{
	fprintf(stdout, "f3 before is: x is: %d\n", *x, *y);
	*x = *x * 7;
	*y = *y * 23;
	fprintf(stdout, "f3 after is: x is: %d\n", *x, *y);
}
