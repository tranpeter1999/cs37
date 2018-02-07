//maxtemp.cpp

/*
template function

works on many data types
*/

int max(int a, int b, int c){
	int big = a;
	if(b > big)
		big = b;
	if(c > big)
		big = c;
	return big;
}

double max(double a, double b, double c){
	double big = a;
	if(b > big)
		big = b;
	if(c > big)
		big = c;
	return big;
}

//OR

template<class T> //or template<typename T>
T max(T a, T b, T c){
	T big = a;
	if(b > big)
		big = b;
	if(c > big)
		big = c;
	return big;
}

template<class T>
T min(T a, T b, T c){
	T small = a;
	if(b < small)
		small = b;
	if(c < small)
		small = c;
	return small;
}

int main(){
	float a,b,c;
	cin >> a >> b >> c; //entered 4.4, 1.1, 2.2
	cout << max(a,b,c) << min(a,b,c); //prints 4.4 1.1
	int d,e,f;
	cin >> d >> e >> f; //entered 4, 8, 5
	cout << max(d,e,f) << min(d,e,f); //prints 8 4
	char g,h,i;
	cin >> g >> h >> i; //entered C A E
	cout << max(g,h,i) << min(g,h,i); //prints E A (remember that lowercase > uppercase)
}

/*
C++ has an STL (standard template library)
-> prewritten templates saved in header files

eg vector STL

MULTIPLE DATA TYPES

->be careful with order of data types! eg all of S should be one data type
*/

template<class S,T,U>
T calc(S a, S b, U c, T d){
	
}