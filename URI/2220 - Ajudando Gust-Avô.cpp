// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ajudando Gust-Avô
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2220

#include <bits/stdc++.h>
using namespace std;

string power(string s, int n){
    string str;
    int p;
    for(int i = 0; i < s.size(); i++){
        p = n;
        while(p--)
            str.push_back(s[i]);
    }
    return str;
}

bool test(string a, string b){
    int k = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i] == b[k])
            k++;
    return (k == b.size());
}

int buscab(string a, string b){
    int ini = 1, fim = a.size()/b.size(), mid;
    int ans = -1;
    while(ini <= fim){
        mid = (ini+fim)/2;
        if(test(a, power(b, mid))){
            ans = mid;
            ini = mid + 1;
        }else{
            fim = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string A, B;
    int t;
    cin >> t;
    while(t--){
        cin >> A >> B;
        A = "0" + A;
        int ans = buscab(A, B);
        cout << (ans == -1 ? 0 : ans) << '\n';
    }
    
    return 0;
}
