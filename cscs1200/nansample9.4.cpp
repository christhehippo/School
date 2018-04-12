// C++ program for the 
// favorite number algorithm

#include <iostream>
using namespace std;

int main ()
//void main()
{
	int n;		// User's favorite number

	// Get the user's favirute number
	cout << "What is your favorite number? ";
	cin  >> n;

	// Compute the next numbrt 
	n = n + 1;

	// Write the output
	cout << endl;
	cout << "My favorite number is 1 more than that, "
		 << n << endl;
	cout << endl << endl;

	return (0);
}
