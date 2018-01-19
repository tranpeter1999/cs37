//cincout2.cpp

/*
in C
gets
fflush

in C++
getline (reads strings with white space)
ignore (use when reading a string or char after numbers to remove the enter key from the string)

*/

#include<iostream>
using namespace std;

int main(){
	const int SIZE = 80;
	char line[SIZE]; //up to 79 chars + null character '\0'
	
	cout << "Enter some text";
	
	cin >> line;
	
	cout << line << endl;
	
	cin.ignore(SIZE,'\n'); //will ignore up to newline or 80 characters
	
	cout << "Enter some text";
	
	cin.getline(line,SIZE);
	
	cout << line << endl;
	
	return 0;
}