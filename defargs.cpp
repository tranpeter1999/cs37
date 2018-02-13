//defargs.cpp

/*
default arguments
	-specify default values for parameters (if you don't specify, you get default)
	-used later for constructors
	-only the right most arguments can be defaulted
	-works with inlin

*/

inline int volume(int length = 1, int width = 1, int height = 1) //HAS TO BE AN ASSIGNED VALUE (i.e. can't do int width = length)
{return length * width * height;}

int main(){
	cout << volume(2,3,4); 	//prints 24
	cout << volume();		//prints 1
	cout << volume(4,5);	//prints 20
	cout << volume(8);		//prints 8
	return 0;
}

/*
can't do the following
	cout << volume(,6,);
*/

