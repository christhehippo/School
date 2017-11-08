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
int main()
{
	
	rectangle box1, box2(3, 7), *box3 = NULL, *box4 = NULL;;

	box3 = (rectangle *) malloc (sizeof(rectangle));
	box3 -> setLength(4);
	box3 -> setWidth(5);

	box4 = new rectangle(1,3); //malloc + call parametered constructor
//	box4 = new rectangle;      //malloc + call parameterless constructor
	
	fprintf(stdout, "box1 area is: %d\n", box1.area());
	fprintf(stdout, "box2 area is: %d\n", box2.area());
	fprintf(stdout, "box3 area is: %d\n", box3 -> area());	
	fprintf(stdout, "box4 area is: %d\n", box4 -> area());


	return(0);
}
