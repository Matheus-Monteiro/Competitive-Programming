// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Nove
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2217

#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n%2 == 0)
			cout << "1" << endl;
		else
			cout << "9" << endl;
	}

	return 0;
}
