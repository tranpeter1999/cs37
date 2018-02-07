//overload.cpp

/*
overloaded functions - functions with the same name but different parameter lists (signatures)

correct function is automatically called 

this is an example of polymorphism
*/

int twice(int x){return x + x;}
double twice(double x){return x + x;}
int twice(int x, int y){return x + y;}
int twice(int x, int y, int z){return x + y + z;}

int main(){
	cout << twice(2,3); //5
	cout << twice(2.222222222); //4.444444444
	cout << twice(3.5); //7.0000000
	cout << twice(2,3,4); //9
	cout << twice(1.11,2.22); //errors
}