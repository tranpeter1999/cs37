//class1.cpp

/*
class - program code for an object
	-encapsulates data members and methods
	-typically saved to a header file
	
-reusable code
	-faster software development
	
ACCESS SPECIFIERS
public 		- access anywhere
private 		- accessed only in class methods
			- control access to certain data members and methods
protected	- used later for inheritance
*/

//FILE ONE
class student{
	public:
		char name[20];
		int t1,t2,t3;
		float avg;
};


//FILE TWO
int main(){
	student s;
	
	cout << "Enter name";
	cin.getline(s.name,20);
	cout << "Enter 3 scores";
	cin >> s.t1 >> s.t2 >> s.t3;
	s.avg = (s.t1 + s.t2 + s.t3)/(float) 3;
	cout << s.name << s.t1 << s.t2 << s.t3 << s.avg;
	return 0;
}