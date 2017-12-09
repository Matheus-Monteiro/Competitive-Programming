// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Volta
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1708

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, a_aux, b_aux;
    int c = 1;
    bool ok = true;
    cin >> a >> b;
    if(a > b)
        swap(a, b);
    a_aux = a;
    b_aux = b;
    while(ok){
        c++;
        a += a_aux;
        b += b_aux;
        if(b-a >= b_aux)
            ok = false;
    }
    cout << c << '\n';
     
    return 0;
}
