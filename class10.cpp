#include<stdio.h>

//REVIEW OF PARAMETER PASSING BY VALUE AND REFERENCE

//prototype
void load(int *, int *, int *); //this function takes 3 user input integers and loads them as variables
void calc(int, int, int, int *, float *); //this function takes the 3 user input integers and calculates the sum and avg
void print(int, int, int, int, float); //this function prints the 3 user input integers and calculations for sum and avg

void load(int *a, int *b, int *c)
{
	
}

void calc(int a, int b, int c, int *sum, float *avg)
{
	
}

void print(int a, int b, int c, int sum, float avg)
{
	
}

//PARAMETER/ARGUMENT

/*
Value passed to a function so the function can perform its task
*/

//SWAPPING & TEMPORARY VARIABLES

a = 20;
b = 10; //swap the two

t = a;
a = b;
b = t;

#include<stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int x = 20, y = 10;
	print("%d %d\n",x,y);
	swap(&x,&y);
	print("%d %d\n",x,y);
	return 0;
}