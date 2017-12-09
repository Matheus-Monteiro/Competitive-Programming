// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fibonacci, Quantas Chamadas?
// Nível: 2
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1029

#include <bits/stdc++.h>

using namespace std;

int c;

int fib(int x){
    c++;
    if(x == 0) return 0;
    if(x == 1) return 1;
    return (fib(x-1) + fib(x-2));
}

int main(){
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        c = 0;
        int r = fib(n);
        cout << "fib(" << n << ") = " << c-1 << " calls = " << r << '\n';
    }
    return 0;
}
