// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Justificador
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1273

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, maior;
    vector<string> v;
    string str;
    bool ok = false;
    
    while(cin >> n and n != 0){
        cin.ignore();
        maior = 0;
        while(n--){
            cin >> str;
            v.push_back(str);
            if(str.size() > maior)
                maior = str.size();
        }
        if(ok)
            cout << "\n";
        ok = true;
        for(int i = 0; i < v.size(); i++)
            cout << setw(maior) << v[i] << "\n";
        v.clear();
    }

    return 0;
}
