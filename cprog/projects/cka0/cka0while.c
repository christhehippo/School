#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned char x = 0;
	unsigned char b2 = 0;
	unsigned char b8 = 0;
	unsigned char b10 = 0;
	unsigned char b16 = 0;
	
	fprintf(stdout, "Base2  Base8  Base10  Base16\n");
	
	
	for (x = 0; x <= 14; x++)
	{
/*		while (x == 0)
		{
			b2 = 0;
			b8 = 0;
			b10 = 0;
			b16 = 0;
		}
		while (x == 1)
		{
			b2 = 1;
			b8 = 1;
			b10 = 1;
			b16 = 1;
		}
		while (x == 2)
		{
			b2 = 10;
			b8 = 2;
			b10 = 2;
			b16 = 2;
		}
		
		while (x == 3)
		{
			b2 = 11;
			b8 = 3;
			b10 = 3;
			b16 = 3;
		}
		
		while (x == 4)
		{
			b2 = 100;
			b8 = 4;
			b10 = 4;
			b16 = 4;
		}
		
		while (x == 5)
		{
			b2 = 101 ;
			b8 = 5;
			b10 = 5;
			b16 = 5;
		}
		
		while (x == 6)
		{
			b2 = 110;
			b8 = 6;
			b10 = 6;
			b16 = 6;
		}
		
		while (x == 7)
		{
			b2 = 111;
			b8 = 7;
			b10 = 7;
			b16 = 7;
		}
		
		while (x == 8)
		{
			b2 = 1000;
			b8 = 10;
			b10 = 8;
			b16 = 8;
		}
		
		while (x == 9)
		{
			b2 = 1001;
			b8 = 11;
			b10 = 9;
			b16 = 9;
		}
		
		while (x == 10)
		{
			b2 = 1010;
			b8 = 12;
			b10 = 10;
			b16 = 10;
		}
		
		while (x == 11)
		{
			b2 = 1011;
			b8 = 13;
			b10 = 11;
			b16 = 11;
		}
		
		while (x == 12)
		{
			b2 = 1100;
			b8 = 14;
			b10 = 12;
			b16 = 12;
		}
		
		while (x == 13)
		{
			b2 = 1101;
			b8 = 15;
			b10 = 13;
			b16 = 13;
		}
		
		while (x == 14)
		{
			b2 = 1110;
			b8 = 16;
			b10 = 14;
			b16 = 14;
		}
		
		while (x == 15)
		{
			b2 = 1111;
*/

		fprintf(stdout, "%4.4hhu", x);
		fprintf(stdout, "   %4.2hhu", x);
		fprintf(stdout, "   %4hhu", x);	
		fprintf(stdout, "   %4A\n", x);
	}










	


	return(0);
}
