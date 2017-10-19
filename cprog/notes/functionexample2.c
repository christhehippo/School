#include <stdio.h>
#include <stdlib.h>


void f1(int j, int k)
{
	j=j*6;
	k=k/3;

}
void f2(int j, int* k)
{
	j=j*6;
	*k=*k/3;
}
void f3(int* j, int k)
{
	*j=*j*6;
	k=k/3;
}
void f4(int* j, int* k)
{
	*j=*j*6;
	*k=*k/3;
}
int main( )
{
	int x=13, y=37;
	fprintf(stdout, "x before: %d\n", x);
	fprintf(stdout, "y before: %d\n", y);

	f1(x, y);
	fprintf(stdout, "x after: %d\n", x);
	fprintf(stdout, "y after: %d\n", y);
	x=13;
	y=37;

	f2(x, &y);
	fprintf(stdout, "x after: %d\n", x);
	fprintf(stdout, "y after: %d\n", y);
	x=13;
	y=37;

	f3(&x, y);
	fprintf(stdout, "x after: %d\n", x);
	fprintf(stdout, "y after: %d\n", y);
	x=13;
	y=37;

	f4(&x, &y);
fprintf(stdout, "x after: %d\n", x);
	fprintf(stdout, "y after: %d\n", y);

	return (0);
}
