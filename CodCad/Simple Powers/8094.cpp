#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double x, y;

	cin >> x >> y;
	cout.precision(4);
	cout << fixed;
	cout << pow(x, y) << endl;
	
	return 0;
}