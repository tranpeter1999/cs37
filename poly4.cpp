//poly4.cpp

/*
Employee
	first
	last
	virtual float calcPay() = 0;
	->Hourly
		wage
		hours
		calcPay()
	->Sales
		salary
		unitPay
		quantity
		calcPay()
	->Crook
		pickpocket
		bribes
		numBribes
		vendMachine
		calcPay()
*/

#define _CRT_SECURE_ND_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Employee{
public:
	Employee(const char *, const char *);
	~Employee(){
		delete[] first;
		delete[] last;
	}
	virtual float calcPay()const = 0;
	virtual void print()const{
		cout << first << " " << last;
	}
private:
	char *first, *last;
};

Employee::Employee(const char *f, const char *l){
	first = new char[strlen(f) + 1];
	strcpy(first,f);
	last = new char[strlen(l) + 1];
	strcpy(last,l);
}

class Hourly:public Employee{
public: 
	Hourly(const char *, const char *, float h = 0.0, float w = 0.0);
	float calcPay() const;
	float print() const;
private:
	float wage,hours;
}

Hourly::Hourly(const char *f, const char *l, float h, float w):Employee(f,l){
	wage = w; hours = h;
}

float Hourly::calcPay()const{
	if(hours <= 40)
		return wage*hours;
	else
		return (40*wage)*(hours-40)*wage*1.5;
}

void Hourly::print()const{
	cout << "Hourly worker: ";
	Employee::print();
}

class Crook:public Employee{
public:
	Hourly(const char *, const char *, float = 0.0, float = 0.0);
	float calcPay()const;
	void print()const;
private:
	float pickPocket,bribe,vendMachine;
	int numBribes;
}

Crook::Crook(const char *f, const char *l, float p, float b, int n, float v):Employee(f,l){
	pickPocket = p; bribe = b; numBribes = n; vendMachine = v;
}

float Crook::calcPay()const{
	return pickPocket + (bribe*numBribes) + vendMachine;
}

float Crook::print()const{
	cout << "Crook worker";
	Employee::print();
}

class Sales:public Employee{
public:
	Sales(const char *, const char *, float s, float u, int q);
	float calcPay()const;
	void print()const;
private:
	float salary; unitPay;
	int quantity;
};

Sales::Sales(const char *f, const char *l, float s, float u, int q):Employee(f,l){
	salary = s; unitPay = u; quantity = q;
}

float Sales::calcPay()const{
	return salary + (unitPay * quantity);
}

void Sales::print()const{
	cout << "Sales Worker: ";
	Employee::print();
}

int main(){ // static binding
	cout << setprecision(2) << showpoint << fixed;
	Hourly h("Joe","Smith",10.5,20.0);
	h.print();
	cout << "Earned $ " << h.calcPay() << endl;
	Sales s("Mary","Jane",2000.0,10.0,50);
	s.print();
	cout << "Earned $ " << s.calcPay() << endl;
	Crook c("Crooked","Crooky",100.0,500.0,10,250.0);
	c.print();
	cout << "Earned $ " << c.calcPay() << endl;
	return 0;
}

int main(){ // dynamic binding
	cout << setprecision(2) << showpoint << fixed;
	Employee *ptr;
	ptr = new Hourly("Joe","Smith",10.5,20.0);
	ptr -> print();
	cout << "Earned $ " << ptr -> calcPay() << endl;
	ptr = new Sales("Mary","Jane",2000.0,10.0,50);
	ptr -> print();
	cout << "Earned $ " << ptr -> calcPay() << endl;
	ptr = new Crook("Crooked","Crooky",100.0,500.0,10,250.0);
	ptr -> print();
	cout << "Earned $ " << ptr -> calcPay() << endl;
	return 0;
}
