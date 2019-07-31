#include <iostream>

using namespace std;

int main(){

	long long int a, b, c, d;
	bool cascata = true;
	
	cin >> a >> b >> c >> d;
	int i = a;
	while(i < (c/2)+1){
		if(a%b == 0)
			break;
		if(i%a == 0 && i%b != 0 && c%i == 0 && d%i != 0){
			cout << i << endl;
			cascata = false;
			break;
		}
		i += a;
	}
	i = c;
	if(cascata){
		if(i%a == 0 && i%b != 0 && c%i == 0 && d%i != 0){
				cout << i << endl;
				cascata = false;
		}
	}
	if(cascata)
		cout << -1 << endl;
		
	return 0;
}