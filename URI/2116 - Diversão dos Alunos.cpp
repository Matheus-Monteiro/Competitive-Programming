// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Diversão dos Alunos
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2116

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, p1, p2;

    cin >> n >> m;

    bool ok, achei = false;
    for(int i = n; i > 1 and !achei; i--){
        ok = true;
        for(int j = 2; j <= sqrt(i) and ok; j++){
            if(i%j == 0)
                ok = false;
        }
        if(ok){
            p1 = i;
            achei = true;
        }
    }
    
    achei = false;
    for(int i = m; i > 1 and !achei; i--){
        ok = true;
        for(int j = 2; j <= sqrt(i) and ok; j++){
            if(i%j == 0)
                ok = false;
        }
        if(ok){
            p2 = i;
            achei = true;
        }
    }
    cout << p1*p2 << "\n";
	return 0;
}
