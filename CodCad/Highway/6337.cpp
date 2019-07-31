#include <iostream>

using namespace std;

int main(){
	
	char l[1000005];
	int n, cont;
	
	cin >> n;
	cont = 0;
	for(int i = 0; i < n; i++){
		cin >> l[i];
		if(l[i] == 'P' || l[i] == 'C')
			cont+=2;
		if(l[i] == 'A')
			cont++;
	}		
	cout << cont << endl;
	
	return 0;
}