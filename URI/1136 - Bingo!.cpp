// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Bingo!
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1136

#include <iostream>
#include <cmath>
#define endl '\n'
const int MAXN = 100;

using namespace std;

int v[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, b;

    while(cin >> n >> b and n != 0 or b != 0){ 
        for(int i = 0; i < b; i++)
            cin >> v[i];
       
        bool ok = true;
        for(int k = 0; k <= n and ok; k++){
            ok = false;
            for(int i = 0; i < b and !ok; i++){
                for(int j = 0; j < b; j++){
                    if(k == fabs(v[i] - v[j]))
                        ok = true;
                }
            }
        }
        (ok) ? cout << "Y" << endl : cout << "N" << endl;
    }
    return 0;
}
