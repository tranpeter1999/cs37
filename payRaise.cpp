/*
PAY RAISE CLASS
5 private data members (floats)
	name
	current pay
	raise %
	raise amount = current pay * raise % / 100
	new pay = current pay + raise amount
4 methods
	constructor with default args. Set name to " " and numbers to 0.0
	destructor to print name being destroyed
	print to print 5 privates
	calcBonus method to handle when an employee gets a bonus.
	
	assume valid input throughout program
instantiation
	payRaise p("Corby Bryan",50000,10);
sample output
	The person's name is Corby Bryan
	The old pay amount is $50000.00
	The raise percentage is 10.00
	The raise amount is $5000.00
	The new pay is $55000.00
	
	How much is the bonus? 10000
	After the bonus
	
	The person's name is Corby Bryan
	The old pay amount is $60000.00
	The raise percentage is 10.00
	The raise amount is $6000.00
	The new pay is $66000.00
	
	The name of Corby Bryan is destroyed
	
	Press any key to continue...
*/

#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class PayRaise{
	public:
		PayRaise(char* = "", float = 0.0, float = 0.0);
		~PayRaise();
		void printData();
		void calcBonus(float);
	private:
		char name[20];
		float oldPay, raisePercentage, raiseAmount, newPay;
};

PayRaise::PayRaise(char* n, float o, float rp){
	strcpy(name,n);
	oldPay = o;
	raisePercentage = rp;
	raiseAmount = oldPay * raisePercentage / 100;
	newPay = oldPay + raiseAmount;
}

PayRaise::~PayRaise(){
	cout << "The name of " << name << " is DESTROYED" << endl;
}

void PayRaise::printData(){
	cout << setprecision(2) << showpoint << fixed;
	cout << "The person's name is " << name << endl;
	cout << "The old pay amount is $" << oldPay << endl;
	cout << "The raise percentage is " << raisePercentage << endl;
	cout << "The raise amount is $" << raiseAmount << endl;
	cout << "The new pay is $" << newPay << endl;
}

void PayRaise::calcBonus(float bonusAmount){
	oldPay += bonusAmount;
	raiseAmount = oldPay * raisePercentage / 100;
	newPay = oldPay + raiseAmount;
}

int main(){
	PayRaise p("Corby Bryan",50000,10);
	p.printData();
	cout << endl << "How much is the bonus?";
	float bonus;
	cin >> bonus;
	p.calcBonus(bonus);
	cout << endl << endl << "after the bonus" << endl;
	p.printData();
	cout << endl;
	return 0;
}
