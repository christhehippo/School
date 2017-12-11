#include <stdio.h>

int main()
{

	int value  = 0x1ced3;
	int valuee = 0130;

	int p1hex = 0x13ca0;
	int p1oct = 0110350;

	int p2hex= 0x1800;
	int p2oct=0204240;

	int p3hex = 0x1e188;
	int p3oct = 0104440;

    fprintf(stdout, "toc hex: %d\n",  value);
	fprintf(stdout, "toc oct: %d\n",  valuee);
    
	fprintf(stdout, "p1hex: %d\n", p1hex);
	fprintf(stdout, "p1oct: %d\n", p1oct);
	
	fprintf(stdout, "p2hex: %d\n", p2hex);
	fprintf(stdout, "p2oct: %d\n", p2oct);
	
	fprintf(stdout, "p3hex: %d\n", p3hex);
	fprintf(stdout, "p3oct: %d\n", p3oct);
	return(0);
}
