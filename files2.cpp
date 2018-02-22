//files2.cpp

/*
new file!

people.dat
Joe Blow
Wendy Smith
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	char name[30];
	ofstream outfile("f:\\people.dat",ios::out);
	
	cout << "Enter a name, ctrl z to quit";
	
	while(cin.getline(name,30))
	{
		outfile << name << endl;
		
		cout << "Enter a name, ctrl z to quit";
	}
	
	outfile.close();
	
	ifstream infile("f:\\people.dat",ios::in);
	
	while(infile.getline(name,30))
		cout << name << endl;
	
	infile.close();
	
	return 0;
}

/*
eof = end of file
*/

while(!infile.eof()){
	infile.getline(name,30);
	cout << name << endl;
}

//IS THE SAME AS

while(infile.getline(name,30))
	cout << name << endl;