//class9.cpp

/*
same class as class8.cpp

main prorammer will write a function for extra credit
	-add 10 points to t2
	-add 20 points to t3
*/

//prototype
void change(student &);

int main(){
	student one(20,30,40);
	one.printData();//20 30 40
	change(one);
	one.printData();//20 40 60
	return 0;
}

void change(student &s){
	s.setTest2(s.getTest2() + 10);
	s.setTest3(s.getTest3() + 20);
}