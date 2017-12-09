// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: É Hora do Duelo!
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1896

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, a, d, h, aa, dd, hh;
    vector<iii> v;
    
    cin >> n >> a >> d >> h;
    while(n--){
        cin >> aa >> dd >> hh;
        v.push_back({aa, {dd, hh}});
    }
    
    bool ok = false;
    int k1 = v.size(), k2 = (1<<k1), aux;
    for(int i = 1; i < k2 and !ok; i++){
        aux = aa = dd = hh = 0;
        for(int j = 0; j < k1 and !ok; j++){
            if(i & (1<<j)){
                aa += v[j].first, dd += v[j].second.first, hh += v[j].second.second;
                aux++;
            }
        }
        if(aux > 1 and aa == a and dd == d and hh == h)
            ok = true;
    }
    cout << (ok ? 'Y' : 'N') << '\n';

    return 0;
}
