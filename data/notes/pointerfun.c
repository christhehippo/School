#include <stdio.h>
#include <stdlib.h>

int main()
{
	signed char   a = 7, 	   *b = NULL;
	unsigned char c = 8, 	   *d = NULL;
	signed int    e = 9,       *f = NULL;
	float 		  g = 3.14159, *h = NULL;
	signed char 		      **i = NULL;

	b = &a;
	d = &c;
	f = &e;
	h = &g;
	i = &b; // i (double pointer) points at single pointer b

	fprintf(stdout, "a contains: %hhd, address of a: %p\n", a, &a);
	fprintf(stdout, "b contains: %p, *b contains: %hhd, address of b: %p\n", b, *b, &b);
	fprintf(stdout, "c contains: %hhu, address of c: %p\n", c, &c);
	fprintf(stdout, "d contains: %p, *d contains: %hhu, address of d: %p\n", d, *d, &d);
	fprintf(stdout, "e contains: %d, address of e: %p\n", e, &e);
	fprintf(stdout, "f contains: %p, *f contains: %d, address of f: %p\n", f, *f, &f);
	fprintf(stdout, "g contains: %.2f, address of g: %p\n", g, &g);
	fprintf(stdout, "h contains: %p, *h contains: %.2f, address of h: %p\n", h, *h, &h);

	// now for the double pointer
	fprintf(stdout, "i contains: %p, *i contains: %p, **i contains: %hhd, address of i: %p\n", i, *i, **i, &i);


	return(0);
}
