#include <iostream>

using namespace std;

int main(){
	
	char l;
	double a, b;
	
	cin >> l;
	cin >> a >> b;
	cout.precision(2);
	cout << fixed;
	
	if(l == 'M')
		cout << a*b << endl;
	else
		cout << (double)a/b << endl;
	
	return 0;
}