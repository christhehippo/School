#ifndef _SQUARE_H
#define _SQUARE_H

#include <math.h>
#include <cstdio>
#include <cstdlib>
#include "rectangle.h"

class square :public rectangle

{


	public:
		square();
		square(int);
		int getSide();
		void setSide(int);
		friend square funtime(const square &);

	private:
		int side;
};

#endif
