//parameters.cpp

/*
Value passed to a function so the function can perform its function

2 types
value - one way
	local copy is made
	no punctuation
	
reference - two way
	passing memory address
	strings/arrays can only be passed by reference
	2 ways to do
		old C way
			put * in function throughout
			put & in call
		newer C++ way (beter)
			put & in parameter list only
		strings/arrays
			same as C
	
can put functions first and then main
OR
can put main first followed by functions
	must prototype functions if main comes first
		 ^ declaration

swap function
x = 20
y = 10
after swap
x = 10
y = 20

t = x;
x = y;
y = t;
*/

#include<iostream>
#include<iomanip>
using namespace std;

//prototypes

void swapByValue(int,int);
void swapByPointer(int *, int *); // old C way