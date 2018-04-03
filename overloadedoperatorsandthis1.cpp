//overloaded operators

/*
makes main easier to write and more consistent

with overlaoded operators

without									with
s.printData();							cout << s;
s.setData();								cin >> s;
sum.add(a,b);							sum = a + b;
										if(s1 > s2)
											-;
										
										
*/

//this1.cpp

/*
										
this pointer- every object has access to its own address through the this pointer

used for operator overloading and cascading.

e.g. 
cin >> x >> y >> z;
s.setTest1(10).setTest2(20).setTest3(30).printData();
sum = a + b + c;

it can also be used to return a modified object

e.g.

return *this;
*/

class student{
	public:
		student();
		void getData(int,int,int);
		void printData();
	private:
		int t1,t2,t3;
		float avg;
};

student::student(){
	t1 = t2 = t3 = avg = 1;
}

void student::getData(int a, int b, int c){
	t1 = a; t2 = b; t3 = c;
	avg = (t1 + t2 + t3)/(float) 3;
}

void student::printData(){
	cout << t1 << t2 << t3 << avg;
	
	//or
	
	cout << this -> t1 << this -> t2 << this -> t3 << this -> avg;
}

int main(){
	student s;
	s.getData(10,20,30);
	s.printData();
}