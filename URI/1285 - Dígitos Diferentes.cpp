// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dígitos Diferentes
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1285

#include <bits/stdc++.h>
 
using namespace std;

int main(){
    
    int n, m, c;
    int v[10];
    string str;
    bool ok;
    
    while(cin >> n >> m){
        c = 0;
        for(int i = n; i <= m; i++){
            memset(v, 0, sizeof(v));
            str = to_string(i);
            for(int j = 0; j < str.size(); j++)
                v[str[j]-'0']++;
            ok = true;
            for(int j = 0; j < 10 and ok; j++)
                if(v[j] > 1)
                    ok = false;
            if(ok)
                c++;
        }
        cout << c << '\n';
    }
    
    return 0;
}
