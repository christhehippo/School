#include "square.h"
#include "rectangle.h"

square::square():rectangle(0,0)
{
	side=0;
	rectangle(side,side);
}

square::square(int side):rectangle(side,side)
{
	this->side=side;
	rectangle(this->side,this->side);
}

int square::getSide()
{
	return(side);
}

void square::setSide(int side)
{
	this->side=side;
	setLength(this->side);
	setWidth(this->side);
}


