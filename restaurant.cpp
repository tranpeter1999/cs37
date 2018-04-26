#include<iostream>
using namespace std;

class Rest{
    friend ostream &operator<<(ostream &out, const Rest &r){
        out << "Good reviews:  " << r.good << endl
            << "Fair reviews:  " << r.fair << endl
            << "Bad reviews:   " << r.bad  << endl
            << "Total reviews: " << r.total<< endl
            << "Good %:        " << r.pergood << "%" << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Rest &r){
        cout << "Enter # of good reviews: "; in >> r.good;
        cout << "Enter # of fair reviews: "; in >> r.fair;
        cout << "Enter # of bad reviews:  ";  in >> r.bad;
        r.total = r.good + r.fair + r.bad;
        r.pergood = (float) r.good/r.total;
        return in;
    }
public:
    Rest(){};
    ~Rest(){};
    bool operator>=(const Rest &r2)const{
        return (pergood >= r2.pergood);
    }
    Rest operator+(const Rest &r2)const{
        Rest sum;
        sum.good = good + r2.good;
        sum.fair = fair + r2.fair;
        sum.bad = bad + r2.bad;
        sum.total = total + r2.total;
        sum.pergood = (float) sum.good/sum.total;
        return sum;
    }
    Rest &operator++(){
        good++;
        total++;
        pergood = (float) good/total;
        return *this;
    }
    Rest operator++(int){
        Rest t = *this;
        good++;
        total++;
        pergood = (float) good/total;
        return t;
    }
private:
    int good, fair, bad, total;
    float pergood;
};

int main(){
    Rest r1,r2;

    cin >> r1 >> r2;
    cout << r1 << endl << r2 << endl;

    cout << r1 + r2;

    if(r1 >= r2)
        cout << "equal or greater than";
}
