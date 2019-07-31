#include <iostream>

using namespace std;

int i= 1;
int fatorial(int n){
	if(n > 0){
		i *= n;
		fatorial(n-1);
	}
}

int main(){
	
	int n;
	cin >> n;
	fatorial(n);
	cout << i << endl;
	
	return 0;
}