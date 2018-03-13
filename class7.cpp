//class7.cpp

/*
same class as class6.cpp
demonstrate default membership copy
	can do one = two
		 corresponding data member of object two are copied to object one
*/

int main(){
	student one, two(10,20,30);
	one.printData();	//0  0  0
	one = two; 			//default membership copy
	one.printData();	//10 20 30
	return 0; //destroys two then one
}