#include <iostream>

using namespace std;

int main(){
	
	int cont, p, n, a;
	
	cin >> p >> n;
	cont = p;
	for(int i = 0; i < n; i++){
		cin >> a;
		cont+=a;
		if(cont < 0)
			cont = 0;
		if(cont > 100)
			cont = 100;
	}
	cout << cont << endl;
	
	return 0;
}