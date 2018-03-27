//class10.cpp

/*
a
t1 : 10
t2 : 20
t3 : 30

b
t1 : 20
t2 : 30
t3 : 40

sum
t1 : 30
t2 : 50
t3 : 70

main
sum.add(a,b);
*/

class student{
	public:
		student(int = 0, int = 0, int = 0);
		~student();
		void getData(int,int,int);
		void printData();
		void add(student,student);
	private:
		int t1,t2,t3;
};

student::student(int a,int b, int c){
	getData(a,b,c);
}

student::~student(){
	cout << t1 << t2 << t3 << "decapitated";
}

void student::getData(int a, int b, int c){
	t1 = a; t2 = b; t3 = c;
}

void student::printData(){
cout << t1 << t2 << t3;}

void student:add(student a, student b){
	t1 = a.t1 + b.t1;
	t2 = a.t2 + b.t2;
	t3 = a.t3 + b.t3;
}

int main(){
	student one(10,20,30), two(20,30,40), sum;
	sum.add(one,two); 	//10 20 30 decapitated
						//20 30 40 decapitated
	sum.printData(); //30 50 70
	return 0; 	//30 50 70 decapitated
				//20 30 40 decapitated
				//10 20 30 decapitated
}
