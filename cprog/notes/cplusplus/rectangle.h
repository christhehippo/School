#ifndef _RECTANGLE_H
#define _RECTANGLE_H


#include <math.h>
#include <cstdio>
#include <cstdlib>

class rectangle
{
	public:
		rectangle();
		rectangle(int,int);
//	   ~rectangle();
		int area();
		int perimeter();
		int getLength();
		int getWidth();
		void setLength(int);	
		void setWidth(int);

	private:
		int length;
		int width;

};

class circle 
{
	public:
		circle();
		circle(int);
		int area();
		int circumference();
		int getRadius();
		void setRadius(int);

	private:
		int radius;
	
};

class triangle
{
	public:
		triangle();
		triangle(int, int, int);
		int area();
		int getSide1();
		int getSide2();
//		int getSide3();
		void setSide1();
		void setSide2();
//		void setSide3();

	private:
		int side1;
		int side2;
		int side3;

};


#endif
