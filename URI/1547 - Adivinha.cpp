// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Adivinha
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1547

#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int v[MAXN];
int q, t, n, aux, p, menor;
bool ok;

int main(){
    cin >> n;
    while(n--){
        cin >> q >> t;
        for(int i = 0; i < q; i++)
            cin >> v[i];  
        menor = 1<<30;
        ok = true;
        for(int i = 0; i < q and ok; i++){
            aux = fabs(v[i]-t);
            if(menor > aux){
                menor = aux;
                p = i;
            }
            if(menor == 0)
                ok = false;
        }
        cout << p+1 << endl;
    }
    
    return 0;
}
