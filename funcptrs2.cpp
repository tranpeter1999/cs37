//funcptrs2.cpp

/*
REMOVING THE SWITCH

Basic idea: using array of function pointers

*f 	|0	|1	|2		|3	|
	 one	 two	 three	 four
*/

void one(int);
void two(int);
void three(int);
void four(int);

void one(int a)
{cout << "You entered " << a << " and are in function one");}

void two(int a)
{cout << "You entered " << a << " and are in function two");}

void three(int a)
{cout << "You entered " << a << " and are in function three");}

void four(int a)
{cout << "You entered " << a << " and are in function four");}

int main(){
	int choice;
	void(*f[4])(int) = {one,two,three,four};
	
	cout << "Enter 1 to 4, 5 to quit";
	cin  << choice;
	
	while(choice >= 1 && choice <= 4){
		(*f[choice-1])(choice); //will call correct function
		
		cout << "Enter 1 to 4, 5 to quit";
		cin  << choice;
	}
	
	cout << "Program done";
	
	return 0;
}