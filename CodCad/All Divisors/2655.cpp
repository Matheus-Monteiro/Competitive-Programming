	#include <iostream>

	using namespace std;

	int main(){

		int x, i = 1;
		cin >> x;
		while(true){
			if(x%i == 0)
				cout << i;
			if(i >= x)
				break;
			if(x%i == 0)
				cout << " ";
			i++;
		}
		cout << endl;
		return 0;
	}