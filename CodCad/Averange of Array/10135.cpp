#include <iostream>
#include <iomanip>

using namespace std;

double media_vetor(int n, int v[]){
	int aux = 0;
	for(int i = 0; i < n; i++)
	    aux += v[i];
    return (double)aux/n;
}

int main(){	
	
	int n, v[100100];
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> v[i];

	cout << setprecision(2) << fixed;

	cout << media_vetor(n,v) << "\n";
}