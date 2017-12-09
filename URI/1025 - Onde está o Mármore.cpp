// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Onde está o Mármore?
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1025

#include <bits/stdc++.h>

using namespace std;

int n, q, v[10100], caso = 1, aux;

int main(){
    while(cin >> n >> q and n != 0 or q != 0){
        
        for(int i = 0; i < n; i++)
            cin >> v[i];     
        
        sort(v, v+n);
        
        cout << "CASE# " << caso << ":" << endl;
        while(q--){
            cin >> aux;
            int *p = lower_bound(v, v+n, aux);
            
            if(p == v+n)
                cout << aux << " not found" << endl;
            else{        
                int aux2 = *p;
                if(aux2 == aux)
                    cout << aux << " found at " << (int)(p-v)+1 << endl;
                else
                    cout << aux << " not found" << endl;
            }
        }

        caso++;
    }


    return 0;
}
