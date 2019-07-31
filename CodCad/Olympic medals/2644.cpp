	#include <iostream>

	using namespace std;

	int main(){

		int o1, p1, b1, o2, p2, b2;
		
		cin >> o1 >> p1 >> b1 >> o2 >> p2 >> b2;
		
		if(o1 > o2)
			cout << "A" << endl;
		if(o1 < o2)
			cout << "B" << endl;
		if(o1 == o2){
			if(p1 > p2)
				cout << "A" << endl;
			if(p1 < p2)
				cout << "B" << endl;
			if(p1 == p2){
				if(b1 > b2)
					cout << "A" << endl;
				if(b1 < b2)
					cout << "B" << endl;
			}
		}
		
		return 0;
	}