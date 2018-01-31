//coutbase.cpp

/*
cpp has io manipulators to print numbers in octal, hexadecimal, decimal

decimal 		- base 10 (0-9)
octal		- base 8  (0-7)
hexadecimal	- base 16 (0-9 + A-F)

2468
    10
= 2 x 10^3 + 4 x 10^2 + 6 x 10 + 8

234
   8
= 2 x 8^2 + 3 x 8 + 4 = 156
					  10
					  
A3C
   16

= 10 x 16^2 + 3 x 16 + 12 = 2620
						  10
						
						
FOR DECIMAL
use
dec
or
setbase(10)

FOR OCTAL
use
oct
or
setbase(8)

FOR HEXADECIMAL
use
hex
or
setbase(16)

setbase can only be 8, 10, or 16
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a = 28;
	int b = 34o; // in octal
	int c = 1Ch; // in hexadecimal
	int n = 28;
	
	cout << n; // prints 28
	cout << hex << n; // prints 1c
	cout << uppercase << n; // prints 1C
	cout << nouppercase << n; // print 1
	cout << oct << n; // prints 34
	cout << dec << n; // prints 28
	
	return 0;
}