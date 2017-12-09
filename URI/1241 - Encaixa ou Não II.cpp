// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Encaixa ou Não II
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1241

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string a, b, aux;
    
    cin >> n;
    
    while(n--){
        cin >> a >> b;
       
        if(a.size() >= b.size()){
            int ini = a.size()-b.size();
            for(int i = ini; i < a.size(); i++)
                aux.push_back(a[i]);

            if(aux == b)
                cout << "encaixa" << endl;
            else
                cout << "nao encaixa" << endl;
        }else
            cout << "nao encaixa" << endl;
            
        aux.clear();
        a.clear();
        b.clear();
    }
    return 0;
}
