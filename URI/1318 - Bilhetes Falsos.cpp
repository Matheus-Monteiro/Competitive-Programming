// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Bilhetes Falsos
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1318

#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, aux;
    set<int> s1, s2;
    
    while(cin >> n >> m and n or m){
        for(int i = 0; i < m; i++){
            cin >> aux;
            auto it = s1.find(aux);
            if(it == s1.end())
                s1.insert(aux);
            else
                s2.insert(aux);
        }
        cout << s2.size() << '\n';
        s1.clear(); 
        s2.clear();
    }

    return 0;
}
