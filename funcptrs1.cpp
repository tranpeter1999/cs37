//functptrs1.cpp

/*
Function pointers

function pointer 	- starting address of a function
				- used for menu handling
				- remove if/switch statements (funcptrs2.cpp)
				
function pointers only work if all the signatures are the same
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
	void (*f) (int); // function pointer declaration
	
	cout << "Enter 1 to 4, 5 to quit";
	cin  << choice;
	
	while(choice >= 1 && choice <= 4){
		switch(choice){
			case 1:  f = one; 	break;
			case 2:  f = two; 	break;
			case 3:  f = three; break;
			default: f = four; //or case 4: f = four; break;
		}
		
		f(choice); //will call correct function
		
		cout << "Enter 1 to 4, 5 to quit";
		cin  << choice;
	}
	
	cout << "Program done";
	
	return 0;
}