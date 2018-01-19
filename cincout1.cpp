//cincout1.cpp

#include<iostream>
using namespace std; //without this line, you would need to specify std:: on all cin and cout statements

int main(){
	cout << "Enter your age" << endl;
	
	int myage;
	
	cin >> myage;
	
	cout << "Enter friend's age" << endl;
	
	int frage;
	
	cin >> frage;
	
	cout << endl << "The two ages are " << myage << " and " << frage << endl;
	
	if(myage > frage)
		cout << endl << "You are older" << endl;
	else if(frage > myage)
		cout << endl << "Your friend is older" << endl;
	else
		cout << endl << "You and your friend are the same age" << endl;

	return 0;
}

/*

STREAM TEMPORARY HOLDING AREA (buffer in C)

<< (out)
 ^ stream insertion operator
 
>> (cin)
 ^ stream extraction operator

local variables local to loops

for(int i =  1; i < n; i ++){
	float b,c;
}

*/

