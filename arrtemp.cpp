//arrtemp.cpp

//prints array for all data types

template<class T>
void printArray(T *a, const int n){ //or void printArray(T a[], const int n){
	for(int i = 0; i < n; i++)
		cout << a[i] < "   ";
	
	cout << endl;
}

template<class T>
void loadArray(T *a, const int n){
	for(int i = 0; i < n; i++){
		cout << "Enter value";
		cin >> a[i];
	}
}

template<class T>
void large2(T *a, const int n){
	int l,l2;
	
	l = a[0];
	
	for(int i = 1; i < n; i++){
		if(a[i] > l){
			l2 = l;
			l = a[i];
		}
	}
	
	cout << l2;
}

template<class T>
void sort(T *a, const int n){
	T t;
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1; j++){
			if(a[j] < a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

int main(){
	const int n1 = 5, n2 = 7, n3 = 6;
	
	int   a[n1] = {2,4,6,8,10};
	float b[n2] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7};
	char  c[n3] = "HELLO";
	
	printArray(a,n1); //2   4   6   8   10
	printArray(b,n2); //1.1   2.2   3.3   4.4   5.5   6.6   7.7
	printArray(c,n3); //H   E   L   L   O   
	
	const int n4 = 5, n5 = 7, n6 = 6;
	
	int   d[n4];
	float e[n5];
	char  f[n6];
	
	loadArray(d,n1);
	loadArray(e,n2);
	loadArray(f,n3);
	
	large2(d,n1);
	large2(e,n2);
	large3(f,n3);
	
	sort(d,n1);
	sort(e,n2);
	sort(f,n3);
	
	printArray(d,n1);
	printArray(e,n2);
	printArray(f,n3);
	
	save;
	save;
	save;
	
	retrieve;
	retrieve;
	retrieve;
	
	printArray(d,n1);
	printArray(e,n2);
	printArray(f,n3);
}