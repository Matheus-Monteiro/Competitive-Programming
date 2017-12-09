// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Entregas do Noel
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2476

#include <bits/stdc++.h>
const int MAX = 1e5 + 100;

using namespace std;

int n, q, x, y;
string str, sub;
vector<string> v;
vector<int> G[MAX];
int nivel[MAX], pai[MAX];
set<string> s;


void dfs(int u){
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(nivel[v] == -1){
            nivel[v] = nivel[u] + 1;
            pai[v] = u;
            dfs(v);
        }
    }
}

int LCA(int a, int b){
    s.insert(v[a]);
    s.insert(v[b]);
    while(a != b){
        if(nivel[a] > nivel[b]){
            a = pai[a];
            s.insert(v[a]);
        }else{
            b = pai[b];
            s.insert(v[b]);
        }
    }
    return s.size();
}

int main(){
    cin >> n >> q;
    
    cin.ignore();
    getline(cin, str);
    
    istringstream iss(str);
    do{
        iss >> sub;
        if(iss)
            v.push_back(sub);
    }while(iss);
        
        
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    
    for(int i = 0; i < n; i++)
        nivel[i] = -1;
    nivel[0] = 0;
       
    dfs(0);
       
    while(q--){
        cin >> x >> y;
        cout << LCA(x-1, y-1) << '\n';
        s.clear();
    }
     
    return 0;
}
