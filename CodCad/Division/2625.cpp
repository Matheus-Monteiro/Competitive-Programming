#include <iostream>

using namespace std;

int main(){

	double x, y;
	cin >> x >> y;
	cout.precision(2);
	cout << fixed << (double)x/y << endl;
	return 0;
}