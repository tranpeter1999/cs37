//overload1.cpp

/*
overloaded operators make main easy to write and more consistent

without overloaded operators
s1.setData(-);
s2.setData(-);
s3.setData(-);
s1.printData();
s2.printData();
s3.printData();

with overloaded operators
cin >> s1 >> s2 >> s3;
cout << s1 << s2 << s3;

<< >> 						friend functions
all other operators 			methods
*/

class student{
	friend ostream &operator<<(ostream &, const student &);
	friend istream &operator>>(istream &, student &);
private:
	int t1,t2,t3;
	float avg;
};

ostream &operator<<(ostream &output, const student &s){
	output << "Test 1 is " << s.t1 << endl;
	output << "Test 2 is " << s.t2 << endl;
	output << "Test 3 is " << s.t3 << endl;
	output << "Average is " << s.avg << endl;
}

istream &operator>>(istream &input, student &s){
	input >> s.t1 >> s.t2 >> s.t3;
	s.avg = (s.t1 + s.t2 + s.t3)/(float) 3;
	return input; //allows cascading input
}

int main(){
	student s;
	cout << "Enter 3 scores";
	cin >> s; //user enters 10 20 30
	cout << s << endl; // 10 20 30 20
	return 0;
}