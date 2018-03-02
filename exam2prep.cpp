//exam2prep.cpp

/*
1) write templates
2) write text file fragments (save/retrieve)
3) short answer

programs for exam 2

inline
scoperes
overload
maxtemp
arrtemp
defargs
funcptr1,2
files1,2,3
*/

template <class T>
T findmiddle(T a, T b, T c){
	if(a > b && a < c || a < b && a > c)
		return a;
	if(b > a && b < c || b < a && b > c)
		return b;
	return c;
}

template <class T>
T findsum(T *a, const int n){
		// ^ or T a[]
	T sum = 0;
	
	for(int i = 0; i < n; i++)
		sum += a[i];
	
	return sum;
}

template <class T>
float findavg(T *a, const int n){
	T sum = 0;
	
	for(int i = 0; i < n; i++)
		sum += a[i];
	
	return sum/(float) n;
}

template <class T>
int nummatches(T *a, const int n, const T b){
	int n = 0;
	
	for(int i = 0; i < n; i++)
		if(a[i] == b)
			n++;
		
	return n;
}

ifstream infile("f:\\payroll.dat",ios::in);
ofstream outfile("f:\\amounts.dat",ios:out);

while(infile.getline(name,30)){
	infile >> hours >> rate >> tp;
	gross = hours*rate;
	tax = gross*tp/100;
	net = gross - tax;
	outfile << name << endl;
	outfile << gross << ' ' << tax << ' ' << net << endl;
	infile.ignore(30,'\n');
}

infile.close();
outfile.close();

