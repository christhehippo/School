#include <stdio.h>
#include <stdlib.h>

typedef long double ldubs;

int main()
{
	
	float    f = 1.824;
	double   d = 7.894;
	ldubs   ld =  6.28;

	int      x = 17;
	int      y = 23;
	int      z = 57;
	
	fprintf(stdout, "f  is: %f (%.2f)\n",     f, f);
	fprintf(stdout, "d  is: %f (%3.1f)\n",    d, d);
	fprintf(stdout, "ld is: %Lf (%4.4Lf)\n", ld, ld);

	f          = (float)y / (float)z;
	fprintf(stdout, "f  is: %f\n", f);

	fprintf(stdout, "a size_t is %lu bytes\n", sizeof(size_t));
	fprintf(stdout, "a float  is %lu bytes\n", sizeof(float));
	fprintf(stdout, "a double is %lu bytes\n", sizeof(double));
	fprintf(stdout, "an ldubs is %lu bytes\n", sizeof(long double));



	return (0);
}
