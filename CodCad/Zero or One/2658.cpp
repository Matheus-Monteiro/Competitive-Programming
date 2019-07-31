	#include <iostream>

	using namespace std;

	int main(){

		int a, b, c;
		
		cin >> a >> b >> c;
		
		if(a == b && b == c)
			cout << "*" << endl;
		if(a == b && b != c)
			cout << "C" << endl;
		if(a != b && b == c)
			cout << "A" << endl;
		if(a == c && a != b)
			cout << "B" << endl;
		return 0;
	}