#include <iostream>

using namespace std;

struct gangorra{
	int p, c;
}typedef g;

int main(){
	
	g a, b;
	
	cin >> a.p >> a.c  >> b.p >> b.c;
	
	if(a.p*a.c < b.p*b.c)
		cout << "1" << endl;
	else
		if(a.p*a.c > b.p*b.c)
			cout << "-1" << endl;
		else
	      	cout << "0" << endl;
		
	return 0;
}