// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Coleção de Pomekon
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2174

#include <bits/stdc++.h>

using namespace std;

int main(){
    set<string> s;
    string str;
    int n;
    
    cin >> n;    
    while(n--){
        cin >> str;
        s.insert(str);
    }
    cout << "Falta(m) " << 151-s.size() << " pomekon(s)." << '\n'; 
        
    return 0;
}
