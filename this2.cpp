//this2.cpp

//remember to put main at bottom if not prototyping
int main(){
	//cascading demo
	
	student s1,s2;
	
	s1.setTest1(10).setTest2(20).setTest3(30).printData(); //prints 102030
	s2.setData(20,30,40).printData(); //prints 203040
	
	return 0; 	//203040gone
				//102030gone
}

class student{ //need & when return *this; in method
	public:
		student(int = 0, int = 0, int = 0);
		~student);
		student &setData(int,int,int);
		student &setTest1(int);
		student &setTest2(int);
		student &setTest3(int);
		int getTest1() const;
		int getTest2() const;
		int getTest3() const;
		void printData() const;
	private: 
		int t1,t2,t2;
};

student::student(int a, int b, int c){
	setData(a,b,c);
}

student::~student(){
	cout << t1 << t2 << t3 << gone;
}

student &student::setData(int a, int b, int c){
	setTest1(a); setTest2(b); setTest3(c);
	return *this; //allows cascading
}

student &student::setTest1(int a){
	t1 = a;
	return *this;
}

student &student::setTest2(int b){
	t2 = b;
	return *this;
}

student &student::setTest3(int c){
	t3 = c;
	return *this;
}

int student::getTest1() const{
	return t1;
}

int student::getTest2() const{
	return t2;
}

int student::getTest3() const{
	return t3;
}

void student::printData() const{
	cout << t1 << t2 << t3;
}