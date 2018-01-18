/*

C++ Notes 1/16/18

INPUT AND OUTPUT

cout<<"enter 3 values";
cin>>x>>y>>z;

#include<iostream>

int main(){
    int x;

    std::cout << "Enter a value\n";
    std::cin >> x;

    std::cout << "The value is " << x; //CONCATENATION THANK THE HEAVENS
}


PARAMETER PASSING

void whatever(int x, float &y)
				^ val	^ ref

FUNCTION OVERLOADING

functions with same name but different parameter lists
correct functions are called automatically
^^ this is function polymorphism

TEMPLATE FUNCTIONS

function that works on many data types

int sum(int a, int b, int c)
{return a + b + c;}

float sum(float a, float b, float c)
{return a + b + c;}

double sum(double a, double b, double c)
{return a + b + c;}

template<class T>

T sum(T a, T b, T c)
{return a + b + c;}

int main(){
	int total = sum(2,3,4);
}

STL -> standard template library
collection of prewritten templates

OBJECTS
like structs

Student
	name
	t1
	t2
	t3
	avg
	load()
	calc()    //functions in objects
	print()
	
CLASS - program code for an object
	> constructors and destructors

THIS POINTER - points to current object

OPERATOR OVERLOADING - reprogram operators

INHERITANCE - copy class

EXCEPTION HANDLING - try catch and throw statements

*/