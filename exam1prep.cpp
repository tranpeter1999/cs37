//exam1prep.cpp

/*
1) short answer
2) write 2 functions, their prototypes, and possible calls

Item ; price ; quantity ; discount %

	a) write a function to allow user to enter data in order given
	
*/

//function a

//prototype
void load(char *, float &, int &, float &);

//function
void load(char *i, float &p, int &q, float &dp){
	cout << "Enter item: ";
	cin.getline(i,12); //12 or more
	cout << "Enter cost, quantity, discount %: ";
	cin << p << q << dp;
}

//call
int main(){
	load(i,p,q,dp);
	return 0;
}

/*
	b) write a function to calculate and return the following
		i)   cost = price*quantity
		ii)  discount = (cost*discount %)/100
		iii) finalCost = cost - disount
*/

//function b

//prototype
void calc(float &, float &, float &, float, int, float);

//function
void calc(float &c, float &d, float &fc, float p, int q, float dp){
	c = p*q;
	d = (c*dp)/100.0;
	fc = c - d;
}

//call
int main(){
	calc(c,d,fc,p,q,dp);
	return 0;
}