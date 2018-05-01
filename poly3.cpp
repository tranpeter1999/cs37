//poly3.cpp

/*
abstract class - a class where no objects can be instantiated
			 - for inheritance only
			 - one or more pure virtual functions means class is abstract

concrete class - 
*/

class mammal
{
	public:
	virtual void talk()const = 0; // pure virtual
};

class Dog:public mammal{
	public:
	void talk()const
	{cout << "Dog says woof";}
};

int main(){
	Dog d;
	d.talk();
};	