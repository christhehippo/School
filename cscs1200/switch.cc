#include <iostream>

using namespace std;

const double PI = 3.14;

int main()
{
	double radius 		 = 0;
	double area   		 = 0;
	double circumference = 0;

	cout << "Enter the radius: ";
	cin  >> radius; 

	area = PI * radius * radius;
	cout << "Area: " << area << endl;
	
	circumference = 2 * PI * radius;
	cout << "Circumference: " << circumference << endl;
	cout << endl;

	return (0);
}
