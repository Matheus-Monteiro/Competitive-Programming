#include <iostream>

using namespace std;

int main(){
	
	int n, a, b, r;
	char c;
	
	cin >> n >> a >> c >> b;
	
	if(c == '*')
		r = a*b;
	else
		r = a + b;
	
	if(r > n)
	   	cout << "OVERFLOW" << endl;
	else
		cout << "OK" << endl;
	
	return 0;
}