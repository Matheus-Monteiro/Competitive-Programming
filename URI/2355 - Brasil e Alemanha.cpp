// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Brasil e Alemanha
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2355

#include <bits/stdc++.h>

using namespace std;

int main(){
    double x, a, b;
    while(cin >> x and x){      
        b = x/90.0;
        a = 7*x/90.0;
        if(a-(int)a != 0)
            a += 1.0;
        cout << "Brasil " << (int)b << " x " << "Alemanha " << (int)a << '\n';
    }
    return 0;
}
