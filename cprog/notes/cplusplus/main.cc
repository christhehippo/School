#include "rectangle.h"

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
	
	circle c1, c2(7), *c3 = NULL, *c4 = NULL;;

	c3 = (circle *) malloc (sizeof(circle));
	c3 -> setRadius(4);

	c4 = new circle(3); //malloc + call parametered constructor
//	box4 = new rectangle;      //malloc + call parameterless constructor
	
	fprintf(stdout, "c1 area is: %d\n", c1.area());
	fprintf(stdout, "c1 circumference is: %d\n", c1.circumference());
	fprintf(stdout, "c2 area is: %d\n", c2.area());
	fprintf(stdout, "c2 circumference is: %d\n", c2.circumference());
	fprintf(stdout, "c3 area is: %d\n", c3 -> area());	
	fprintf(stdout, "c3 circumference is: %d\n", c3 -> circumference());
	fprintf(stdout, "c4 area is: %d\n", c4 -> area());
	fprintf(stdout, "c4 circumference is: %d\n", c4 -> circumference());
	
	
	
	return(0);
}
