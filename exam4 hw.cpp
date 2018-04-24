//Fractions Class with operator overloading

/*
Peter Tran
Sean Miller
Jenny Shah
Amanda Tan
*/

#include<iostream>
using namespace std;

class Fraction{
	friend ostream &operator<<(ostream&, const Fraction&);
	friend istream &operator>>(istream&, Fraction&);
    public:
        Fraction(int = 0, int = 1);
        ~Fraction();
        void    printData();
        void    add(Fraction, Fraction);
        void    sub(Fraction, Fraction);
        void    mul(Fraction, Fraction);
        void    div(Fraction, Fraction);
        void    recip();
        void    reduce();
        int     getNum();
        int     getDen();
        int     GCD(int,int);
        //Fraction operator+(Fraction &lhs, const Fraction &rhs) const;
        Fraction operator+(const Fraction &rhs)const{
            return Fraction(num * rhs.den + rhs.num * den, den * rhs.den);
        }
        Fraction operator-(const Fraction &rhs)const{
            return Fraction(num * rhs.den - rhs.num * den, den * rhs.den);
        }
        Fraction operator*(const Fraction &rhs)const{
            return Fraction(num * rhs.num, den * rhs.den);
        }
        Fraction operator/(const Fraction &rhs)const{
            return Fraction(num * rhs.den, den * rhs.num);
        }
        bool operator==(const Fraction &rhs)const{
            return (num == rhs.num && den == rhs.den);
        }
        bool operator!=(const Fraction &rhs)const{
            return (num != rhs.num || den != rhs.den);
        }
        Fraction &operator++();
        Fraction operator++(int);
    private:
        int num, den;
};

Fraction::Fraction(int n, int d){
    /*if(d == 0){
        cout << "WARNING! - Attempted to set denominator to 0, defaulting to 1" << endl;
        d = 1;
    }*/

    int g = GCD(n,d);

    num = n/g;
    den = d/g;

    if(den < 0){
        den *= -1;
        num *= -1;
    }
}

Fraction::~Fraction(){
    /*if(den == 0)
        cout << "undefined fraction (divided by 0) destroyed" << endl;
    else if(den == 1 || num == 0)
        cout << num << " destroyed" << endl;
    else
        cout << num << "/" << den << " destroyed" << endl;*/
}

int Fraction::getNum(){
    return num;
}

int Fraction::getDen(){
    return den;
}

void Fraction::reduce(){
    int g = GCD(num,den);

    num /= g;
    den /= g;

    if(den < 0){
        den *= -1;
        num *= -1;
    }
}

/*Fraction operator+(Fraction &lhs, const Fraction &rhs)const{
    return Fraction(lhs.num + rhs.num, lhs.den + rhs.den);
}*/

Fraction &Fraction::operator++(){
    int temp = num;
    num = den;
    den = temp;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction tempFraction = *this;
    int temp = num;
    num = den;
    den = temp;
    return tempFraction;
}

ostream &operator<<(ostream &output, const Fraction &f){
	if(f.den == 0)
        output << "undefined";
    else if(f.den == 1 || f.num == 0)
        output << f.num;
    else
        output << f.num << "/" << f.den;
	return output;
}

istream &operator>>(istream &input, Fraction &f){
	input >> f.num >> f.den;
	f.reduce();
	return input;
}

void Fraction::printData(){
    if(den == 0)
        cout << "undefined" << endl;
    else if(den == 1 || num == 0)
        cout << num << endl;
    else
        cout << num << "/" << den << endl;
}

void Fraction::add(Fraction a, Fraction b){
    int anum = a.getNum() * b.getDen();
    int bnum = b.getNum() * a.getDen();

    num = anum + bnum;
    den = a.getDen() * b.getDen();

    this -> reduce();
}

void Fraction::sub(Fraction a, Fraction b){
    int anum = a.getNum() * b.getDen();
    int bnum = b.getNum() * a.getDen();

    num = anum - bnum;
    den = a.getDen() * b.getDen();

    this -> reduce();
}

void Fraction::mul(Fraction a, Fraction b){
    num = a.getNum() * b.getNum();
    den = a.getDen() * b.getDen();

    this -> reduce();
}

void Fraction::div(Fraction a, Fraction b){
    num = a.getNum() * b.getDen();
    den = a.getDen() * b.getNum();

    this -> reduce();
}

void Fraction::recip(){
    int t   = num;
    num     = den;
    den     = t;

    if(den < 0){
        den *= -1;
        num *= -1;
    }
}

int Fraction::GCD(int a, int b){
    if(a == 0)
        return b;
    return GCD(b%a,a);
}

int main(){
    Fraction f1,f2,sum,diff,prod,quo;

    cout << "Enter the first fraction: ";
    cin >> f1;
    cout << "Enter the second fraction: ";
    cin >> f2;
    cout << "The first fraction is " << f1 << endl << "The second fraction is " << f2 << endl;

    sum = f1 + f2;
    diff = f1 - f2;
    prod = f1*f2;
    quo = f1/f2;

    cout << "The sum  is " << sum << endl;
    cout << "The diff is " << diff << endl;
    cout << "The prod is " << prod << endl;
    cout << "The quo  is " << quo << endl;

    if(f1 == f2)
        cout << "EQUAL!" << endl;
    if(f1 != f2)
        cout << "NOT EQUAL!" << endl;

    cout << "Preincrements: " << ++f1 << " " << ++f2 << endl;
    cout << "Postincrements: " << f1 ++ << " " << f2++ << endl;
    cout << "After postincrements: " << f1 << " " << f2 << endl;

    return 0;
}
