#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int n;
	double num;
	
	cin >> n;
	
	while(n--){
		cin >> num;
		cout.precision(4);
		cout << fixed;
		cout << sqrt(num) << endl;
	}
	
	return 0;
}