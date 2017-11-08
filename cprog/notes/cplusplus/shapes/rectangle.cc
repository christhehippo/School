#include "rectangle.h"


rectangle :: rectangle()
{
	length = 0;
	width  = 0;
}

rectangle :: rectangle(int length, int width)
{
	this -> length = length;
	this -> width  = width;
}

int rectangle  :: area()
{
	return (length * width);
}

int rectangle :: perimeter()
{
	return (length + length + width + width);
}

int rectangle :: getLength()
{
	return(length);
}

int rectangle :: getWidth()
{
	return (width);
}

void rectangle :: setLength(int length)
{
	this -> length = length;
}

void rectangle :: setWidth(int width)
{
	this -> width = width;
}

circle :: circle()
{
	radius = 0;
}

circle :: circle(int radius)
{
	this -> radius = radius;
}

int circle :: area()
{
	return ((radius * radius) * M_PI);
}

int circle :: circumference()
{
	return (2 * M_PI * radius);
}

int circle :: getRadius()
{
	return (radius);
}

void circle :: setRadius(int radius)
{
	this -> radius = radius;
}

/*int triangle :: triangle()
{
	side1 = 0;
	side2 = 0;
	side3 = 0;
}

int triangle :: triangle(int side1, int side2, int side3)
{
	this -> side1 = side1;
	this -> side2 = side2;
	this -> side3 = side3;
}

int area()
{
	return ((side1 * side2) / 2)
}
*/
