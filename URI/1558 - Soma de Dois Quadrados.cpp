// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma de Dois Quadrados
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1558

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    bool ok;
    
    while(cin >> n){   
        ok = false;
        for(int i = 0; i <= sqrt(n) and !ok; i++)
            for(int j = 0; j <= sqrt(n) and !ok; j++)
                if(i*i+j*j == n)
                    ok = true;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
