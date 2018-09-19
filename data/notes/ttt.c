#include <stdio.h>
#include <stdlib.h>

#define  N		0
#define  S		1
#define  E		2
#define	 W		3
#define  NW		4
#define  NE		5
#define  SW		6
#define  SE		7

struct sector
{
	char mark;
	struct sector **link;
};
typedef struct sector Sector;

int main()
{
	int num        = 0;
	int value      = 0;
	int result     = 2;
	int offsetNW   = -1;
	int offsetSE   = -1;
	int offsetNE   = -1;
	int offsetSW   = 1;
	int location   = 0;
	int hack       = 1;
	int pwn3d      = -2;
	unsigned char row  = -3;
	Sector *arena  = NULL;
	Sector *tmp    = NULL;
	
	arena          = (Sector *)  malloc (sizeof (Sector)   * 9);
	for (num = 0; num < 9; num++)
		(arena+num) -> link  = (Sector **) malloc (sizeof (Sector *) * 8);

	for (num = 0; num < 9; num++) // for each sector in the arena
	{
		if ((num % 3) == 0)
			row        = row + 3;
		tmp = (arena+num);
		//tmp -> link[W] = (arena+(((num-1) % 3)+row));
		tmp -> link[E]  = (arena+(((num % 3) + 1) % 3) + row);
		tmp -> link[W]  = (arena+((num + 2) % 3) + row);
		tmp -> link[N]  = (arena+((6 + num) % 9));
		tmp -> link[S]  = (arena+((3 + num) % 9));
//		tmp -> link[NW] = (arena+((num+((row/3)+1)*8)-(3*num)-num-(num%2);

		location        = ((num+((row/3)+1)*8)-(3*num)-num);
		if ((num != 0) && (num % 4) == 0)
		{
			location    = location + (4 * offsetNW);
			offsetNW     = offsetNW + 2;
		}
		tmp -> link[NW] = (arena+location);

//		location        = ((num+((row/3)+1)*8)-(3*num)-num);
		if ((num % 4)  == 0)
		{
			location    = location + (4 * (offsetSE * hack));
			hack        = hack - offsetSE;
			offsetSE    = offsetSE * -1;
		}
		tmp -> link[SE] = (arena+location);

		location        = ((num + (2 * value)) % 8);
		value           = value + 1;
		if ((num >= 4) && (num % 2) == 0)
		{
			location    = result;
			result      = result * 2;
		}
		tmp -> link[NE] = (arena+location);
	//	fprintf (stdout, "NE num: %d -> %d\n", num, location);

		if ((num >= 2) && (num <= 6) && (num % 2) == 0)
		{
			location    = pwn3d;
			pwn3d       = pwn3d + (6 * offsetSW);
			offsetSW    = offsetSW * -1;
		}
		tmp -> link[SW] = (arena+location);
		fprintf (stdout, "SW num: %d -> %d\n", num, location);
		
//		tmp -> link[NW] = tmp -> link[N] -> link[W];
//		tmp -> link[NE] = tmp -> link[N] -> link[E];
//		tmp -> link[SW] = tmp -> link[S] -> link[W];
//		tmp -> link[SE] = tmp -> link[S] -> link[E];

	}
	// fix 0's west mapping
	//tmp = (arena+num);
	//tmp -> link[W] = (arena+2);

	// ((num+8)-(3*num))-num

	return (0);
}
