//class4.cpp

/*
declare an array as a data member
            0   1   2   3   4
e.g. sales [ ] [ ] [ ] [ ] [ ]

going to add a private method to our class (private utility function)
*/

class person{
	public:
		person();
		void getSales();
		void printSales();
	private:
		float sales[5];
		float totalSales();
};

person::person(){
	for(int i = 0; i < 5; i++){
		sales[i] = .0;
	}
}

void person::getSales(){
	for(int i = 1; i < 6; i++){
		cout << "Enter the data for month " << i;
		cin >> sales[i-1];
	}
}

void person::printSales(){
	cout << setprecision(2) << showpoint << fixed;
	
	for(int i = 0; i < 5; i++){
		cout << sales[i] << " ";
	}
	
	cout << endl << endl;
	
	cout << "Total sales are " << totalSales() << endl;
}

float person::totalSales(){
	float sum = .0;
	
	for(int i = 0; i < 5; i++){
		sum += sales[i];
	}
	
	return sum;
}


//DIFF FILE

int main(){
	person p;
	p.getSales();
	p.printSales();
	
	return 0;
}


//MAIN REWRITE

int main(){
	person p[10];
	
	for(int i = 0; i < 10; i++){
		p[i].getSales();
		p[i].printSales();
	}
	
	return 0;
}