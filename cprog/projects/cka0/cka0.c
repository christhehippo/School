#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned char x = 0;
	int bin = 0;

	fprintf(stdout, " base 2 | base8 | base10 | base16\n");
	fprintf(stdout, "--------+-------+--------+--------\n");	
	for (x = 0; x <= 15; x++)
	{
		if (x == 0)
		{
			bin = 0;
		}
		if (x == 1)
		{
			bin = 1;
		}
		if (x == 2)
		{
			bin = 10;
		}
		if (x == 3)
		{
			bin = 11;
		}
		if (x == 4)
		{
			bin = 100;
		}
		if (x == 5)
		{
			bin = 101;
		}
		if (x == 6)
		{
			bin = 110;
		}
		if (x == 7)
		{
			bin = 111;
		}
		if (x == 8)
		{
			bin = 1000;
		}
		if (x == 9)
		{
			bin = 1001;
		}
		if (x == 10)
		{
			bin = 1010;
		}
		if (x == 11)
		{
			bin = 1011;
		}
		if (x == 12)
		{
			bin = 1100;
		}
		if (x == 13)
		{
			bin = 1101;
		}
		if (x == 14)
		{
			bin =1110;
		}
		if (x == 15)
		{
			bin = 1111;
		}
		fprintf(stdout, "%2c", ' ');	
		fprintf(stdout, "%4.4d ", bin);
		fprintf(stdout, " | ");
		fprintf(stdout, "%4.3o ", x);
		fprintf(stdout, "%c| ", ' ');
		fprintf(stdout, "%4hhu ", x);	
		fprintf(stdout, "%2c| ", ' ');
		fprintf(stdout, " 0x0%X\n", x);
	}










	


	return(0);
}
