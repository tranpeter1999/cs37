//poly1.cpp

/*
Polymorphism - ability for objects of different classes related by inheritance to respond differently to the same method call
		    - correct method is automatically called
*/

class mammal{
	public:
	virtual void talk()const
	{cout << "mammal says hi";}
};

class Dog:public mammal{
	public:
	void talk()const
	{cout << "Dog says woof";}
};

class Cat:public mammal{
	public:
	void talk()const
	{cout << "Cat says meow";}
};

int main()
{//static binding
	Cat c;
	c.talk(); // Cat says meow
	mammal m;
	m.talk(); // mammal says hi
	Dog d;
	d.talk(); // Dog says woof
	return 0;
}

int main()
{//dynamic binding
	mammal *ptr;
	ptr = new Cat;
	ptr -> talk();
	delete ptr;
	ptr = new mammal;
	ptr -> talk();
	delete ptr;
	ptr = new Dog;
	ptr -> talk();
	delete ptr;
	return 0;
}