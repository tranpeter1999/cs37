//class2.cpp

/*
Introducing methods to classes

constructor 	- automatically called when an object is instantiated
			- must have same name as class

destructor 	- automatically called when an object is out of scope			
*/

//FILE ONE
#include<iostream>
using namespace std;

class student{
	public:
		student(); // constructor
		void setData(int,int,int);
		void printData();
	private:
		int t1,t2,t3;
		float avg;
}

student::student(){
	t1 = t2 = t3 = 1;
	avg = (t1 + t2 + t3)/(float) 3;
}

void student::setData(int a, int b, int c){
	t1 = a, t2 = b, t3 = c;
	avg = (t1 + t2 + t3)/(float) 3;
}

void student::printData(){
	cout << t1 << t2 << t3 << avg;
}



//FILE TWO
int main(){
	student one, two;
	one.printData();
	two.setData(20,30,40);
	two.printData();
	return 0;
}