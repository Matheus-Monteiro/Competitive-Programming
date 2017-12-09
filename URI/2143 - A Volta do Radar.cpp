// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Volta do Radar
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2143

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    
    while(cin >> t){   
        while(t--){
            cin >> n;
            if((n-2)%2 == 0)
                cout << 2*n-2 << "\n";
            else
                cout << 2*n-1 << "\n";
        }
    }
	return 0;
}
