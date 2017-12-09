// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Falha do Motor
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2167

#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n, a, resposta = 0;
	vector<int> v;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> 	a;
		v.push_back(a);
	}
	int aux = v[0];
	int j = 0;
	while(n--){
		if(aux > v[j]){
			resposta = j + 1;
			break;
		}
		aux = v[j];
		j++;
	}
	cout << resposta << endl;

	return 0;
}
