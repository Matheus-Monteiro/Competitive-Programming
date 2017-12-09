// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Bactéria I
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2356

#include <bits/stdc++.h>

using namespace std;

string t, p;
vector<int> b;
int n, m;

void kmpPreprocess(){
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m){
        while(j >= 0 and p[i] != p[j])
            j = b[j];
        i++; j++;
        b[i] = j;
    }
}

bool kmpSearch(){
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 and t[i] != p[j])
            j = b[j];
        i++; j++;
        if(j == m)
            return true;
    }
    return false;
}

int main(){
    while(cin >> t >> p){
        n = t.size();
        m = p.size();
        b.resize(n+5);
        kmpPreprocess();
        if(kmpSearch()) cout << "Resistente" << '\n';
        else cout << "Nao resistente" << '\n';
        b.clear();
    } 
    return 0;
}
