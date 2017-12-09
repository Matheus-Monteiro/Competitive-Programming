// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Conversa Internacional
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1581

#include <bits/stdc++.h>

using namespace std;

int main(){
    set<string> s;
    string str;
    int n, k;
    
    cin >> n;
    while(n--){
        cin >> k;
        cin.ignore();
        while(k--){
            cin >> str;
            s.insert(str);
        }
        if(s.size() == 1){
            auto it = s.begin();
            cout << *it << "\n";
        }else
            cout << "ingles" << "\n";
        s.clear();
    }
    return 0;
}
