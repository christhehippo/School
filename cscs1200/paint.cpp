#include <iostream>
#include <math.h>

using namespace std;

const float gallonsPerSqFt    = 120;


int main ()
{
	float doorL	      = 0;
	float doorW       = 0;
	float doorSqFt    = 0;
	
	float windowL1    = 0;
	float windowL2    = 0;
	float windowW1    = 0;
	float windowW2    = 0;
	float windowSqFt1 = 0;
	float windowSqFt2 = 0;

	float bookL       = 0;
	float bookW       = 0;
	float bookSqFt    = 0;
	
	float roomL       = 0;
	float roomW       = 0;
	float roomH       = 0;
	float roomSqFt    = 0;	

	float gallonsNeededF = 0;
	int   gallonsNeededI = 0;
	// Store varaibles
	cout << "Door length: ";
	cin  >> doorL;
	cout << "Door width: ";
	cin  >> doorW;
	doorSqFt = doorL * doorW;

	cout << "Window 1 length: ";
	cin  >> windowL1;
	cout << "Window 1 width: ";
	cin  >> windowW1;
	windowSqFt1 = windowL1 * windowW1;

	cout << "Window 2 length: ";
	cin  >> windowL2;
	cout << "Window 2 width: ";
	cin  >> windowW2;
	windowSqFt2 = windowL2 * windowW2;

	cout << "Bookshelf length: ";
	cin  >> bookL;
	cout << "Bookshelf width: ";
	cin  >> bookW;
	bookSqFt = bookL * bookW;

	cout << "Room length: ";
	cin  >> roomL;
	cout << "Room width: ";
	cin  >> roomW;
	cout << "Room height: ";
	cin  >> roomH;
	// Caclulate sq ft of all four walls
	roomSqFt = ((roomW * roomH) * 2) + ((roomL * roomH) * 2);

	// Subtract paint not needed for win, bookshelf, door
	roomSqFt =  roomSqFt - doorSqFt;
	roomSqFt =  roomSqFt - windowSqFt1;
	roomSqFt =  roomSqFt - windowSqFt2;
	roomSqFt =  roomSqFt - bookSqFt;

	// Total sq ft / 120 for 1 gallon per 120 sq ft

	gallonsNeededF = roomSqFt / gallonsPerSqFt;
	gallonsNeededI = ceil(gallonsNeededI);
	
	if (gallonsNeededF > gallonsNeededI)
		gallonsNeededI++;

	cout << "Gallons needed: " << gallonsNeededI << endl;
	

	
	return (0);
}
