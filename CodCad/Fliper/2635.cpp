	#include <iostream>

	using namespace std;

	int main(){

		int a, b;
		
		cin >> a >> b;
		
		if(a == 0)
			cout << "C" << endl;
		else
			if(b == 0)
				cout << "B" << endl;
			else
				cout << "A" << endl; 
		
		return 0;
	}