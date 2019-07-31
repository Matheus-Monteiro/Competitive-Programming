#include <iostream>

using namespace std;

int main(){
	int n, p, x, y, cont=0;
	
	cin >> n >> p;
	
	while(n--){
		cin >> x >> y;
		if(x+y >= p)
			cont++;
	}
	cout << cont << endl;
		
	return 0;
}