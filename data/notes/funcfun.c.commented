// 
// In Depth Analysis of the In-class project on 8/23/18
//
// James G Williams
//
// Notes:
// Any questions ask me anytime
//
//
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h> 
//
// Libraries with useful things
//
/////////////////////////////////////////////////////////////////////

// function prototypes
char func1 (char  a, char  b); // full "pass by value" function
char func2 (char  a, char *b); // a is "by value", b "by address"
void func3 (char *x, char *y); // x and y are "by address"
//
// Declaring some functions that will be used later on
//
/////////////////////////////////////////////////////////////////////

int main(){

	char  j    = 5;
	char  k    = 7;
	char *m    = NULL;
	char *zard = NULL;
	//
	// Declaring Variables
	//
	// j and k are actual numbers 5 and 7 respectively
	//
	// m and zard are pointers. Currently "pointing" (*) to NULL
	//
	/////////////////////////////////////////////////////////////////

	m    = &j;
	zard = &k;
	// 
	// Note: I highlight the variables with () to make them stand out more
	//
	// 		m = &j;
	//
	// This sets the POINTER (m) EQUAL to the ADDRESS of (j)
	//
	// 		Example: 
	// 
	// 		the ADDRESS of (j):  0xdeadbeef
	// 		the VALUE of (j): 	 5
	//
	// 		the ADDRESS of (m):  0xcoffee
	// 		the VALUE of (m):    NULL
	//
	// We want (m) to POINT to (j), so we pass (m) the ADDRESS of (j)
	//
	// (&) Denotes an address, so: 0xdeadbeef = &j
	//
	// 		m = &j;
	// 
	// (m) now EQUALS: 0xdeadbeef
	//
	// END RESULTS:
	// 
	// (j) ADDRESS: 0xdeadbeef
	// (j) VALUE:	5
	//
	// (m) ADDRESS: 0xc0ffee 
	// (m) VALUE: 	0xdeadbeef 
	//
	/////////////////////////////////////////////////////////////////
	//
	// 		zard = &k;
	//
	// This sets the POINTER (zard) EQUAL to the ADDRESS of (k)
	//
	//		Example:
	//		
	//		the ADDRESS of (k):		0xbeebee
	//		the VALUE of (k):		7
	//
	//		the ADDRESS of (zard):	0xc05fefe
	//		the VALUE of (zard):	NULL
	//
	// We want (zard) to POINT to (k), so we pass (zard) the ADDRESS of (k)
	//
	// (&) Denotes an address, so: 0xbeebee = &k
	//
	//		zard = &k;
	//
	// (zard) now EQUALS: 0xbeebee
	//
	// END RESULTS:
	// 
	// (k) ADDRESS:		0xbeebee
	// (k) VALUE:		7
	//
	// (zard) ADDRESS:	0xc05fefe
	// (zard) VALUE:	0xbeebee
	//
	/////////////////////////////////////////////////////////////////
	//
	// Now with declaring:
	// 
	// 		m    = &j;   :: m    = 0xdeadbeef
	// 		zard = &k;   :: zard = 0xbeebee
	//
	// (*m) or (*zard) now states, "the value at that address"
	//
	//		*m    :: the VALUE at the ADDRESS 0xdeadbeef is: 5
	//		*zard :: the VALUE at the ADDRESS 0xbeebee is: 	 7
	//
	/////////////////////////////////////////////////////////////////

	fprintf(stdout, " j    is: %hhd\n",  j);
	fprintf(stdout, " k    is: %hhd\n",  k);
	fprintf(stdout, "*m    is: %hhd\n", *m);
	fprintf(stdout, "*zard is: %hhd\n", *zard);
	//
	// These statements will print out the values currently residing
	// in each variable
	//
	// " j    is: 5"
	// " k    is: 7"
	// "*m    is: 5"
	// "*zard is: 7"
	//
	/////////////////////////////////////////////////////////////////

	*zard = func1(j, k);
	// 
	// We are reassigning (*zard) to the return value of func1(j, k)
	//
	// The function (func1) takes two char types, (j) and (K) are
	// both chars, so no extra action is needed
	//
	// j = 5; j enters the function as (a)
	// k = 7; k enters the function as (b)
	//
	/////////////////////
	//	Start Values:  //
	//	a = 5		   //
	//	b = 7		   //
	/////////////////////
	//
	// 		a = a + 7; (a) now EQUALS 12
	// 		b = b * 2; (b) now EQUALS 14
	//
	/////////////////////
	//	Values:		   //
	// 	a = 12		   //
	//  b = 14		   //
	/////////////////////
	//
	// fprintf(stdout, "a is: %hhd\n", a);
	// fprintf(stdout, "b is: %hhd\n", b);
	// 
	// These statements print out the values of (a) and (b) at this point
	//
	// "a is: 12"
	// "b is: 14"
	//
	//
	// 		a = a + 3; (a) now EQUALS 15
	// 		b = b - 2; (b) now EQUALS 12
	//
	/////////////////////
	//  End Values:	   //
	//  a = 15		   //
	//  b = 12		   //
	/////////////////////
	//
	// return(b);
	//
	// Now the function will "return" (b)
	//
	/////////////////////////////////////////////////////////////////
	//
	// *zard = func1(j, k);
	//
	// func1(j, k) RETURNS (b), which at the end of the function,
	// is now 12
	//
	// *zard = 12
	//
	// *zard is the VALUE at the ADDRESS of (k)
	// (earlier we declared that zard = &k, or that (zard) EQUALS the
	//  ADDRESS of (k) )
	//
	// So now since *zard is the VALUE at the ADDRESS 0xbeebee,
	// that VALUE is now 12
	//
	// Finally:
	//
	// *zard = 12
	//  k 	 = 12
	//
	/////////////////////////////////////////////////////////////////

	fprintf(stdout, " j    is: %hhd\n",  j);
    fprintf(stdout, " k    is: %hhd\n",  k);
    fprintf(stdout, "*m    is: %hhd\n", *m);
    fprintf(stdout, "*zard is: %hhd\n", *zard);
	//
	// These statements will print out the updated values, if any
	//
	// " j    is: 5 "
	// " k    is: 12"
	// "*m    is: 5 "
	// "*zard is: 12"
	//
	/////////////////////////////////////////////////////////////////

	j = func2(*m, zard);	
//  j = func2( j, zard); This statement is equivalent
	//
    // We are reassigning (j) to the return value of func2(*m, zard)
    //
	// We declared the function:
	//
	// char func2 (char  a, char *b);
	//
	//
	// the Function (func2) requires a char type,
	// since we are using (m) we must dereference what it is pointing to.
	// (m) by itself EQUALS 0xdeadbeef, an ADDRESS. We need a char value,
	// so we use (*m) to specify the use of the VALUE at the given ADDRESS,
	// which in our case is 5.
	//
	// Now the Function (func2) also requires a char pointer type, we
	// then pass it the char pointer (zard), since (zard) is "pointing"
	// to the ADDRESS of a char.
	// 
	//
    // *m      =  5 	*m enters the function as (a)
    // (*)zard = 12 	zard enters the function as (b)
    //
    /////////////////////
    //  Start Values:  //
    //  a = 5          //
    //  b = 12         //
    /////////////////////
    //
    //      a = a + 7; (a) now EQUALS 12
    //      b = b * 2; (b) now EQUALS 24
    //
    /////////////////////
    //  Values:        //
    //  a = 12         //
    //  b = 24         //
    /////////////////////
    //
    // fprintf(stdout, "a is: %hhd\n", a);
    // fprintf(stdout, "b is: %hhd\n", b);
    //
    // These statements print out the values of (a) and (b) at this point
    //
    // "a is: 12"
    // "b is: 14"
    //
    //
    //      a = a + 3; (a) now EQUALS 15
    //      b = b - 2; (b) now EQUALS 22
    //
    /////////////////////
    //  End Values:    //
    //  a = 15         //
    //  b = 22         //
    /////////////////////
    //
    // return(a);
    //
    // Now the function will "return" (a)
    //
    /////////////////////////////////////////////////////////////////
    //
    // j = func2(*m, zard);
    //
    // func2(*m, zard) RETURNS (a), which at the end of the function,
    // is now 15
	//
	// j = 15
	//
	// Since *m is the VALUE at the ADDRESS: 0xdeadbeef
	//
	// *m now EQUALS 15
	//
	// Finally:
	//
	//  j = 15
	// *m = 15
	//
	/////////////////////////////////////////////////////////////////

 	fprintf(stdout, " j    is: %hhd\n",  j);
    fprintf(stdout, " k    is: %hhd\n",  k);
    fprintf(stdout, "*m    is: %hhd\n", *m);
    fprintf(stdout, "*zard is: %hhd\n", *zard);
	//
	// These statements print out the updated values of the variables
	//
	// " j    is: 15"
	// " k    is: 22"
	// "*m    is: 15"
	// "*zard is: 22"
	//
	/////////////////////////////////////////////////////////////////

	func3(&k, &j);
//  func3(zard, m); This statement is equivalent
    //
    // We declared the function:
    //
    // char func3 (char *x, char *y);
    //
    //
    // the Function (func3) requires two pointer types,
    // and we are passing (&k) and (&j) to the function 
	//
	// (k) and (j) by themselves are char types. We must tell the function
	// what their ADDRESS is
    //
	// We use (&) to specify the ADDRESS of a VALUE
	// 
	// (&j) EQUALS 0xdeadbeef BECAUSE (j) has the ADDRESS 0xdeadbeef
	// 
	// (&k) EQUALS 0xbeebee BECUASE (k) has the ADDRESS 0xbeebee
    //
	//
    // &k = 0xbeebee    	&k enters the function as (x)
    // &j = 0xdeadbeef     	&j enters the function as (y)
    //
	// Now our inputs, (&k) (&j), replace (x) and (y)
	//
	// 		So *x is now:
	//		
	//			*(0xbeebee)
	//
	// 		and *y is now:
	//
	//			*(0xdeadbeef)
	//
	// Since we are POINTING to an ADDRESS we get the VALUE at that ADDRESS
	//
	//		*(0xbeebee)   = 22		k value corresponding to *x
	//
	//		*(0xdeadbeef) = 15		j value corresponding to *y
	//
    /////////////////////
    //  Start Values:  //
    //  *x = 22        //
    //  *y = 15        //
    /////////////////////
    //
    //      *x = *x + 7; (*x) now EQUALS 29
    //      *y = *y * 2; (*y) now EQUALS 30
    //
    /////////////////////
    //  Values:        //
    //  *x = 29        //
    //  *y = 30        //
    /////////////////////
    //
    // fprintf(stdout, "*x is: %hhd\n", *x);
    // fprintf(stdout, "*y is: %hhd\n", *y);
    //
    // These statements print out the values of (a) and (b) at this point
    //
    // "*x is: 29"
    // "*y is: 30"
    //
	//
    //      *x = *x + 3; (*x) now EQUALS 32
    //      *y = *y - 2; (*y) now EQUALS 28
    //
    /////////////////////
    //  End Values:    //
    //  *x = 32        //
	//  *y = 28		   //
	/////////////////////
	//
	// The function does not return a value
	//
	/////////////////////////////////////////////////////////////////
	//
	// Since we modified VALUES at ADRESSESS directly those VALUES
	// have been modified, contrary to the "copies" we made in
	// the first function
	//
	//  j 	 = 28
	//  k 	 = 32
	// *m 	 = 28
	// *zard = 32
	//
	/////////////////////////////////////////////////////////////////
	
	fprintf(stdout, " j    is: %hhd\n",  j);
    fprintf(stdout, " k    is: %hhd\n",  k);
    fprintf(stdout, "*m    is: %hhd\n", *m);
    fprintf(stdout, "*zard is: %hhd\n", *zard);
	//
	// These values print out the updated values of the variables
	//
	// " j    is: 28"
	// " k    is: 32"
	// "*m    is: 28"
	// "*zard is: 32"
	//
	/////////////////////////////////////////////////////////////////

	return(0);
	//
	// Closes the program
	//
	/////////////////////////////////////////////////////////////////
}

char func1 (char a, char b){

	a = a + 7;
	b = b * 2;

	fprintf(stdout, "a is: %hhd\n", a);
	fprintf(stdout, "b is: %hhd\n", b);

	a = a + 3;
	b = b - 2;

	return (b);
}
//
// say
// x = 0; 
//
// When you have equations like;
// x = x + 1;
//
// You are replacing the previous value with a new one,
// using the previous value plus 1
//
// x = 0 + 1
//
// x now equals 1
//
// so if we go once more;
//
// x = x + 1;
//
// we would have:
//
// x = 1 + 1
//
// x now equals 2
//
/////////////////////////////////////////////////////////////////////

char func2 (char a, char *b){

 	 a =  a + 7;
    *b = *b * 2;
 
    fprintf(stdout, "a is: %hhd\n", a);
    fprintf(stdout, "b is: %hhd\n", *b);
 
	 a =  a + 3;
    *b = *b - 2;

	return (a);
}
//
// Same as func1
//
/////////////////////////////////////////////////////////////////////

void func3 (char *x, char *y){

	*x = *x + 7;
	*y = *y * 2;
 	
    fprintf(stdout, "*x is: %hhd\n", *x);
	fprintf(stdout, "*y is: %hhd\n", *y);
 
 	*x = *x + 3;
    *y = *y - 2;
}
//
// Same as func1
//
/////////////////////////////////////////////////////////////////////
