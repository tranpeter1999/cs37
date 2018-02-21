//files1.cpp

/*
save #'s
retrieve #'s
print

example file
5
3
732
21
43
<eof> //end of file marker (close file!)
*/

#include<iostream>
#include<fstream> //must include for text files
using namespace std;

int main(){
	int num;
	          //v any name
	ofstream outfile("f:\\nums.dat",ios::out);
	
	cout << "Enter a number to save, ctrl z to quit";
	
	while(cin >> num){
		outfile << num << endl;
		cout << "Enter a number to save, ctrl z to quit";
	}
	
	outfile.close();
	
	//retrieve and print text file
	          //v any name
	ifstream infile("f:\\nums.dat",ios::in);
	
	while(infile >> num)
		cout << num << " ";
	
	cout << endl;
	
	infile.close();
	
	return 0;
}