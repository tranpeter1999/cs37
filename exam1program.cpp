/*
Peter Tran
IVC ID: 1104985
*/

#include<iostream>
#include<iomanip>
using namespace std;

struct student {
	string fname, lname;
	double hwk1,hwk2,hwk3,e1,e2,thwk,te,p;
	char grade;
};

void initialize(int &size){
	cout << "How many students? ";
	cin >> size;
}

void input(int size, struct s[]){
	for(int i = 0; i < size; i ++){
		cout << "Enter the student's name (first <space> last)";
		cin >> s[i].fname >> " " >> s[i].lname;
	}
}

int main(){
	int size;

	initialize(size);

	student class[size];

	input(size);
}
