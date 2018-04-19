//exam4.cpp

/*
coinage class
int p - # of pennies
int n - # of nickels
int d - # of dimes
int q - # of quarters
int num - # of coins = p + n + d + q
float amt - # of money in piggy bank = .01*p + .05*n + .1*d + .25*q;

overload<= //if(c1<=c2)
				return true if amount of c1 <= amt of c2

		bool operator <= (const coinage &rhs)const
{return amt <= rhs.amt};

overload+ e.g. sum = c1 + c2;

		coinage operator + (const coinage $rhs)const
{return coinage(p+rhs.p,n+rhs.n,d+rhs.d,q+rhs.q,num+rhs.num,amt+rhs.amt)}

		overload preincrement+ e.g. ++c1; add 1 to each coin type

coinage:: &coinage::operator++()
{p++; n++; d++; q++; num += 4; amt += .41;}

		overload postincrement eg c++;

coinage coinage::operator++(int){
	coinage temp = *this;
	p++; n++; d++; q++; num+=4; amt += .41;
	return this;
}

		overload stream extraction e.g. cin >> c1;
		
istream &operator>>(istream &input, coinage &c){
	input >> c.p >> c.n >> c.d >> c.q;
	c.num = c.p + c.n + c.d + c.q;
	c.amt = .01*p + .05*n + .1*d + .25*q;
	return input;
}

		overload stream insertion e.g. cout << c1;

ostream &operator<<(ostream &output, coinage &c){
	output << c.p << c.n << c.d << c.g << c.num << c.amt;
	return output;
}
*/