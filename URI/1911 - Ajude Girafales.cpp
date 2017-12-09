// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ajude Girafales
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1911

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    map<string, string> mapa1, mapa2;
    string str1, str2;
    
    while(cin >> n and n != 0){
        cin.ignore();
        while(n--){
            cin >> str1 >> str2;
            mapa1[str1] = str2;
        }
        
        cin >> m;
        cin.ignore();
        while(m--){
            cin >> str1 >> str2;
            mapa2[str1] = str2;
        }
        
        int cont = 0, erro;
        bool ok;
        
        for(auto &p : mapa1){
            auto aux = mapa2.find(p.first);
            if(aux != mapa2.end()){
                erro = 0;
                ok = true;
                for(int j = 0; j < p.second.size() and ok; j++){
                    if(p.second[j] != aux->second[j]){
                        ok = false;
                        erro++;
                        if(erro == 1)
                            ok = true;
                        if(erro > 1)
                            cont++;
                    }
                }
            }
        }
        
        cout << cont << "\n";
        mapa1.clear();
        mapa2.clear();
    
    }
    return 0;
}
