//scoperes.cpp

/*
scope resolution operator ::

allows access to variables (data members and methods later) that are outside the current scope
*/

float num = 2.345; //global variables

int main(){
	int num = 5;
	cout << num; //5
	cout << ::num; //2.345
	return 0;
}