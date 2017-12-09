// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Preenchimento de Vetor II
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1177

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int main(){
	int v[MAX] = {0}, x, t, i, m=0;;
    cin >> t;
		
		for(i = 0 ; i < 1000 ; i++){
			
			if(m == t)
				m = 0;
			v[i] += m;
			m++;
		}

		for(i = 0 ; i < 1000 ; i++)
			cout << "N[" << i << "] = " << v[i] << endl;
	return 0;
}
