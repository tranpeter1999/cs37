//finalexam.cpp

class point{
	friend ostream &operator<<(ostream &,const point&);
public:
	point(int a = 0, int b = 0){x = a; y = b;}
	int getx()const {return x;}
	int gety()const {return y;}
protected:
	int x,y;
}

ostream &operator<<(ostream &output, const print&p){
	output << "[" << p.x << ", " << p.y << "]" << endl;
	return output;
}