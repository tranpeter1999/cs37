//overload2.cpp

class student{
	friend ostream &operator<<(ostream &, const student &);
	friend istream &operator>>(istream &, student &);
public:
	student &operator+=(int);
	student &operator++(); 		//pre increment
	student operator++(int); 	//post increment -> uses a dummy int
private:
	int t1,t2,t3;
	float avg;
};

student &student::operator+=(int e){
	t1 += e; t2 += e; t3 += e; avg += e;
	return *this;
}

student &student::operator++(){
	t1++; t2++; t3++; avg++;
	return *this;
}

student student::operator++(int){
	student temp = *this;
	t1++; t2++; t3++; avg++;
	return temp;
}

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


//main version A
int main(){
	student s;
	cout << "Enter 3 scores";
	cin >> s; //enter 10 20 30
	cout << s; //10 20 30 20
	s += 5;
	cout << s; //15 25 35 25
	++s;
	cout << s; //16 26 36 26
	return 0;
}

//main version B
int main(){
	student s;
	cout << "Enter 3 scores";
	cin >> s; //enter 10 20 30
	cout << s; //10 20 30 20
	s += 5;
	cout << s; //15 25 35 25
	++s;
	cout << s; //16 26 36 26
	cout << ++s; //17 27 37 27
	cout << s++; //17 27 37 27
	cout << s; //18 28 38 28
	
	return 0;
}