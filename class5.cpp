//class5.cpp

/*
add destructor to our class
	automatically called when object goes out of scope
	must have the same name as the class WITH ~ at the front
	
	e.g. ~person();
	
	LATER ON we will explore destructors to return dynamic data to free memory
*/

//back to class2.cpp

class student{
	public:
		student();
		~student();
		void setData(int,int,int);
		void printData();
	private:
		int t1,t2,t3;
};

student::student(){
	t1 = t2 = t3 = 1;
}

student::~student(){
	cout << t1 << t2 << t3 << " destroyed"; 
	system("PAUSE"); //FOR STUDIO
}

student::setData(int a, int b, int c){
	t1 = a; t2 = b; t3 = c;
}

student::printData(){
	cout << t1 << t2 << t3;
}

//NEW FILe

int main()
{
	student one,two;
	one.printData(); //prints 1 1 1
	two.setData(10,20,30);
	two.printData(); //prints 10 20 30
	return 0; //one and two go out of scope, so output will print
			  //1 1 1 destroyed
			  //10 20 30 destroyed
}