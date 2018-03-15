//class8.cpp

/*
in C++, we have get and set functions
			  v        v
     returns value of   sets value of
	one and only one	one and only one
	data member		data member
	
get and set are used to modify private data members
you can control how they're modified
for example
add 5 points extra credit to t2
main
one.t2 += 5; DOESN'T WORK BECAUSE t2 IS PRIVATE
we do it with a set function
one.setTest2(one.getTest2 + 5);
*/

class student{
	public:
		student(int = 0, int = 0, int = 0);
		~student();
		void setData(int,int,int);
		void setTest1(int);
		void setTest2(int);
		void setTest3(int);
		int getTest1();
		int getTest2();
		int getTest3();
		void printData();
	private:
		int t1,t2,t3;
};

student::student(int a, int b, int c){
	setData(a,b,c);
}

student::~student(){
	cout << t1 << t2 << t3 << "terminated";
}

void student::setData(int a, int b, int c){
	setTest1(a);
	setTest2(b);
	setTest3(c);
}

void student::setTest1(int a){
	t1 = a;
}

void student::setTest2(int b){
	t2 = b;
}

void student::setTest3(int c){
	t3 = c;
}

/*
bounds checking is done in set functions
*/

void student::setTest1(int a){
	if(a >= 0 && a <= 100)
		t1 = a;
	else{
		cout << "INVALID TEST SCORE";
		
		do{
			cout << "Enter a valid test score";
			cin >> t1;
			
			if(a < 0 || a > 100)
				cout << "INVALID AGAIN YA NUMPTY! SHOULD BE FROM [0,100]";
		}while(a < 0 || a > 100);
	}
}

int student::getTest1(){
	return t1;
}

int student::getTest2(){
	return t2;
}

int student::getTest3(){
	return t3;
}

void student::printData(){
	cout << t1 << t2 << t3;
}

int main(){
	student one;
	one.printData(); // 0  0  0
	one.setTest1(20);
	one.setTest2(30);
	one.setTest3(40);
	one.printData(); // 20 30 40
	int x,y,z;
	x = one.getTest1();
	y = one.getTest2();
	z = one.getTest3();
	cout << x << y << z; // 20 30 40
	return 0; // 20 30 40 terminated
}