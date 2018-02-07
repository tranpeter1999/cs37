//inline.cpp

/*
inline functions used for short frequently called functions to save on the function call overhead
																		^ the time and memory used

before the program runs, a text substitution is done at function call

*/
#include<iostream>
#include<iomanip>
using namespace std;

inline double cube(const double s){
	return s * s * s;
}

int main(){
	double side;
	cout << "Enter the length of a side for a cube" << endl;
	cin >> side;
	cout << "Volume is " << cube(side);
	
	return 0;
}

/*
function call overhead

stack - LIFO structure
        ^ last in first out
		
push - adding to stack
pop  - removing from stack

call function
stack return address
stack local variables

return from function
pop return address
pop local variables

^^^^ THIS TAKES TIME AND MEMORY, inline skips this
*/