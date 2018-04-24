//inherit2.cpp and dynamicstrings

/*
"is a" relationship - inheritance
	e.g. Seth is a Dork
		class Seth:public Dork
"has a" relationship - composition
	e.g. A student has a collection of 3 scores
		int t1,t2,t3;
		
"A worker is a employee"

Employee
First, Last
  |
Worker
Hours, Wage

dynamic strings
-allocate needed amount of memeory

new - allocates memory / constructor
delete - return string to free memory / destructor                  
*/

class Employee{
public: 
	Employee(const char *, const char *);
	void print()const{
		cout << first << " " << last;}
	~Employee();
private:
	char *first, *last; // dynamic strings
};

Employee::Employee(const char *f, const char *l){
	first = new char[strlen(f)+1];
	strcpy(first,f);
	last = new char[strlen(l)+1];
	strcpy(last,l);
	cout << "Inside employee constructor";
}

Employee:~Employee(){
	cout << "Inside employee destructor to kill " << first << " " << last;
	delete[] first;
	delete[] last;
}

class Worker:public Employee{
public:
	Worker(const char *, const char *, float, float);
	float getPay()const{
		return wage*hours;}
private:
	float wage, hours;
};

Worker::Worker(const char *f, const char *l, float h, float w)::Employee(f,l){ // call base constructor
	wage = w; hours = h;
	cout << "Inside worker constructor";
}

void Worker::print()const{
	Employee::print(); // call base print
	cout << hours << wage << getPay();
}

int main(){
	Worker w("Joe", "Smith", 10.5, 20.0);
	w.print();
	return 0;
}
