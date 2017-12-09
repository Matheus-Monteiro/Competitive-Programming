// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Zero vale Zero
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1871

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int a, b, r;
    string str;
    
    while(cin >> a >> b and a != 0 or b != 0){
        r = a + b;
        str = to_string(r);
        for(char &p : str)
            if(p != '0')
                cout << p;
        cout << "\n";
    }
    return 0;
}
