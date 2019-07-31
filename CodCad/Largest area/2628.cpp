#include <iostream>

using namespace std;

int main(){

	double a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	if(a*b > c*d)
		cout << "Primeiro" << endl;
	else
		if(a*b < c*d)
			cout << "Segundo" << endl;
		else
			cout << "Empate" << endl;
	return 0;
}