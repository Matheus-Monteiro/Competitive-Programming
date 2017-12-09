// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Encaixa ou Não I
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1240

#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    int aux, t;
    bool buraco;
    cin >> t;
    while(t--){
        cin >> a >> b;
        buraco = true;
        if(a.size() >= b.size()){
            aux = a.size() - b.size();
            for(int i = aux, j = 0; i < a.size() && buraco; i++, j++)
                if(a[i] != b[j])
                    buraco = false;
            (buraco) ? cout << "encaixa" << endl : cout << "nao encaixa" << endl;    
        }else
            cout << "nao encaixa" << endl;
    }
    return 0;
}
