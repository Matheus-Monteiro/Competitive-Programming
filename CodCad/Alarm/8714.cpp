#include <iostream>

using namespace std;

int main(){
	
	int h1, m1, h2, m2, t1, t2;
	
	while(cin >> h1 >> m1 >> h2 >> m2 && h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0){
		t1 = 60*h1 + m1;
		t2 = 60*h2 + m2;
		
		if(t1 < t2)
			cout << t2 - t1 << endl;
		else
			cout << 24*60 + t2 - t1 << endl;
	}
	
	return 0;
}