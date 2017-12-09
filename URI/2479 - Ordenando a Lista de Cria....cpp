// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ordenando a Lista de Cria...
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2479

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, sc = 0, nc = 0;
    string str;
    char c;
    vector<string> v;
    
    cin >> n;
    cin.ignore();
    while(n--){
        cin >> c >> str;
        (c == '+') ? sc++ : nc++;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    cout << "Se comportaram: " << sc << " | " << "Nao se comportaram: " << nc << '\n'; 
    
    return 0;
}
