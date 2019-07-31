#include <iostream>

using namespace std;

int main(){

	int n, d, soma = 0, cont_d = 1;
	
	cin >> n;
	
	while(n--){
		cin >> d;
		soma += d;
		if(soma < 1000000)
			cont_d++;
	}
	cout << cont_d << endl;
	return 0;
}