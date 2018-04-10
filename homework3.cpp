#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Fraction{
    public:
        Fraction(int = 0, int = 1);
        ~Fraction();
        void printData();
        void add(Fraction, Fraction);
        void sub(Fraction, Fraction);
        void mult(Fraction, Fraction);
        void div(Fraction, Fraction);
        void recip();
        void reduce();
        int getNum();
        int getDen();
        int GCD(int,int);
    private:
        int num, den;
};

Fraction::Fraction(int n, int d){
    if(d == 0)
        d = 1;

    int g = GCD(n,d);

    num = n/g;
    den = d/g;
}

Fraction::~Fraction(){
    if(den == 1 || num == 0)
        cout << num << " destroyed" << endl;
    else
        cout << num << "/" << den << " destroyed" << endl;
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
}

void Fraction::printData(){
    if(den == 1 || num == 0)
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

void Fraction::mult(Fraction a, Fraction b){
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
    int t = num;
    num = den;
    den = t;
}

int Fraction::GCD(int a, int b){
    if(a == 0)
        return b;
    return GCD(b%a,a);
}

int main(){
    Fraction one(3,7),two(4,12),add,sub,mult,div;
    cout << "Fraction one is "; one.printData();
    cout << "Fraction two is "; two.printData();

    add.add(one,two);
    cout << "Fraction two added to fraction one = "; add.printData();

    sub.sub(one,two);
    cout << "Fraction two subtracted from fraction one = "; sub.printData();

    mult.mult(one,two);
    cout << "Fraction one multiplied by fraction two = "; mult.printData();

    div.div(one,two);
    cout << "Fraction one divided by fraction two = "; div.printData();

    one.recip();
    two.recip();
    cout << "The reciprocal of fraction one is "; one.printData();
    cout << "The reciprocal of fraction two is "; two.printData();

    return 0;
}
