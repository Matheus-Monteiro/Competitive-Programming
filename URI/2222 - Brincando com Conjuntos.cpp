// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Brincando com Conjuntos
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2222

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int count_bits(ll z){
    int cont = 0;
    while(z){
        z &= (z-1);
        cont++;
    }
    return cont;
}

int main(){
    ll bitmask[10005], aux;
    int t, n, c, q, o, x, y;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i = 1; i <= (n+2); i++)
            bitmask[i] = 0LL;
            
        for(int i = 1; i <= n; i++){
            cin >> c;
            for(int j = 0; j < c; j++){
                cin >> aux;
                bitmask[i] |= (1LL<<aux);
            }
        }
        cin >> q;
        while(q--){
            cin >> o >> x >> y;
            if(o == 1){
                aux = bitmask[x]&bitmask[y];
                cout << count_bits(aux) << '\n';
            }else{
                aux = bitmask[x]|bitmask[y];
                cout << count_bits(aux) << '\n';
            }
        }
    }

    return 0;
}
