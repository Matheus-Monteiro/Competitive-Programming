// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Acima da Média
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1214

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k, nota;
	double media;
	vector<int> v;
	
	cin >> t;
	while(t--){
		cin >> n;
		k = 0;
		for(int i = 0; i < n; i++){
			cin >> nota;
			v.push_back(nota);
			k += nota;
		}
		media = double(k)/double(n);
		k = 0;
		for(int i = 0; i < n; i++)
			if(v[i] > media)
				k++;
		cout << setprecision(3) << fixed;
		cout << (double(k)/double(n))*100 << "%" << '\n';
		v.clear();
	}
	
	return 0;
}
