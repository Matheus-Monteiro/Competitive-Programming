// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Validador de Senhas
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2253

#include <bits/stdc++.h>

using namespace std;

int main(){
    string senha;
    bool u, l, d, fuck;
    
    while(getline(cin, senha)){
        if(senha.size() < 6 or senha.size() > 32)
            cout << "Senha invalida." << '\n';
        else{
            fuck = true;
            u = l = d = false;
            for(int i = 0; i < senha.size(); i++){
                if(islower(senha[i]))
                    l = true;
                else
                    if(isupper(senha[i]))
                        u = true;
                    else
                        if(isdigit(senha[i]))
                            d = true;
                        else
                            fuck = false;
            }
            if(fuck and u and l and d)
                cout << "Senha valida." << '\n';
            else
                cout << "Senha invalida." << '\n';
        }
    }
        
    return 0;
}
