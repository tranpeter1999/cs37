//overload3.cpp

/*

*/

class student{
	friend ostream &operator<<(ostream&, const student&);
public:
	student(int = 0, int = 0, int = 0);
	student operator+(const student &rhs)const{
		return student(t1+rhs.t1,t2+rhs.t2,t3+rhs.t3);
	}
	bool operator>(const student&rhs)const{
		return t1 > rhs.t1>;
	}
private:
	int t1, t2, t3;
};

student::student(int a, int b, int c)
	:t1(a),t2(b),t3(c) //new way
{}

ostream operator<<(ostream &output, const student &s){
	output << s.t1 << s.t2 << s.t3;
	return output;
}

int main(){
	student s1(10,20,30),s2(20,30,40),sum;
	sum = s1 + s2;
	cout << sum; //30 50 70
	if(s1 > s2)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}