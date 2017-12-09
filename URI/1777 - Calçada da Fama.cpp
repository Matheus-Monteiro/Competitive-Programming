// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Calçada da Fama
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1777

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<ii> v, s;

void merge(){
    bool flag;
    for(int i = 0; i < v.size(); i++){
        flag = true;
        for(int j = 1; j < s.size(); j++){
            if(max(v[i].first, s[j].first) <= min(v[i].second, s[j].second)){
                s[j] = {min(v[i].first, s[j].first), max(v[i].second, s[j].second)};
                flag = false;
            }
        }
        if(flag)
            s.push_back(v[i]);
    }
}

bool buscab(int x){
    int b = 1, e = s.size()-1, m;
    while(b <= e){
        m = (b+e)/2;
        if(s[m].first <= x and s[m].second >= x)
            return true;
        if(s[m].first > x)
            e = m - 1;
        if(s[m].first < x)
            b = m + 1;
    }
    return false;
}

int main(){
    int t, q, n, c, fi, ss, caso = 1;
    
    cin >> t;
    
    while(t--){
        cin >> n >> c;
        for(int i = 0; i < c; i++){
            cin >> fi >> ss;
            v.push_back({min(fi, ss), max(fi, ss)});
        }
        sort(v.begin(), v.end());
        s.push_back({-1, -1});
        merge();
        
        cin >> q;
        int ans = 0;
        while(q--){
            cin >> ss;
            if(buscab(ss))
                ans++;
        }        
        cout << "Caso #" << caso++ << ": " << ans << '\n';
        v.clear();
        s.clear();
    }
    
    return 0;
}
