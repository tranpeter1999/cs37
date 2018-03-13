//class6.cpp

/*
adding default arguments to constructor of a class
only rightmost arguments can be defaulted

main - in past						main - with def args
student one;						student one(10,20,30);
one.setData(10,20,30);
*/


class student{
	public:
		student(int = 0, int = 0, int = 0);
		~student();
		void setData(int, int, int);
		void printData();
	private:
		int t1,t2,t3;
};

student::student(int a, int b, int c){
	setData(a,b,c);
}

student::~student(){
	cout << t1 << t2 << t3 << "destroyed";
}

void student::setData(int a, int b, int c){
	t1 = a; t2 = b; t3 = c;
}

void student::printData(){
	cout << t1 << t2 << t3;
}

int main(){
	student one(10,20,30);
	student two(25,35);
	student three;
	student four(80);
	
	one.printData();	//10 20 30
	two.printData();	//25 35 0
	three.printData();	//0  0  0
	four.printData();	//80 0  0
	
	return 0; //destroys four, then three, then two, then one
}