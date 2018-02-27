//files3.cpp

/*
save/retrieve as array of structs

e.g. 4 studnts
name
t1,t2,t3
avg

LOOKS LIKE THIS!!!

students.dat
name
t1 t2 t3 avg

Joe Blow
20 30 40 30

Wendy Smith
40 50 60 50

    <2 more>
*/

#include<iostream>
#include<fstream>
using namespace std;

struct student{
	char name[20];
	int t1, t2 ,t3;
	float avg;
};

int main(){
	student s[4];
	int i;
	
	//load array from keyboard
	for(i = 0; i < 4; i++){
		cout << "Enter a name";
		
		cin.getline(s[i].name,20);
		cout << "Enter 3 scores";
		cin >> s[i].t1 >> s[i].t2 >> s[i].t3;
		s[i].avg = (s[i].t1 + s[i].t2 + s[i].t3)/ (float) 3;
		cin.ignore(20,'\n');
		cout << endl << endl;
	}
	
	//save array to text file
	ofstream outfile("f:\\students.dat",ios::out);
	
	for(i = 0; i < 4; i++){
		outfile << s[i].name << endl;
		outfile << s[i].t1 << " " << s[i].t2 << " " << s[i].t3 << " " << s[i].avg << endl;
	}
	
	outfile.close();
	
	//retrieve file
	ifstream infile("f:\\students.dat",ios::in);
	
	for(i = 0; i < 4; i++){
		infile.getline(s[i].name,20);
		infile << s[i].t1 << s[i].t2 << s[i].t3 << s[i].avg;
		infile.ignore(20,'\n');
	}
	
	//print array
	for(i = 0; i < 4; i++){
		cout << s[i].name << endl;
		cout << "test scores " << s[i].t1 << " " << s[i].t2 << " " << s[i].t3;
		cout << "average     " << s[i].avg << endl << endl;
	}
}
