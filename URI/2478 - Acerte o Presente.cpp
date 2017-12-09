// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Acerte o Presente
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2478

#include <bits/stdc++.h>

using namespace std;

struct tentar{
    string name;
    string one, two, three;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    tentar v[110];
    string nome, presente;
    
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> v[i].name >> v[i].one >> v[i].two >> v[i].three;
        while(cin >> nome >> presente){
            bool ok = false;
            for(int i = 0; i < n; i++)
                if(v[i].name == nome)
                    if(presente == v[i].one or presente == v[i].two or presente == v[i].three)  
                        ok = true;
            if(ok)
                cout << "Uhul! Seu amigo secreto vai adorar o/" << '\n';
            else
                cout << "Tente Novamente!" << '\n';
        }
    }
    return 0;
}
