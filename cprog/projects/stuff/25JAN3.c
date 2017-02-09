#include <stdio.h>
#include <stdlib.h>





int main()
{
	char a, b, c, d, e, f;
	a = 0xA4; /* 0x55, 0xAA - hexadecimal value */
	b = 0x1F;
	c = d = 0;
	c = a & b;
	d = a | b;
	e = a ^ b;
	f = ~a;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	fprintf(stdout, "%hhX AND %hhX is: %hhX\n", a, b, c);
	fprintf(stdout, "%hhX OR %hhX is: %hhX\n", a, b, d);
	fprintf(stdout, "%hhX XOR %hhX is: %hhX\n", a, b, e);
	fprintf(stdout, "NOT %hhX is: %hhX\n", a, f);
	fprintf(stdout, "a: %hhX, b: %hhX\n", a , b); 

 











	return (0);
}
