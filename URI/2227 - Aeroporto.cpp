// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Aeroporto
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2227

#include <bits/stdc++.h>
const int MAX = 110;
using namespace std;

vector<vector<int> > G;
vector<int> grau, res;
int n, m, x, y, caso = 1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while(cin >> n >> m and n or m){
        G.resize(n);
         
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            G[x-1].push_back(y-1);
        }
        
        grau.resize(n);
        
        for(int i = 0; i < n; i++)
            grau[i] += G[i].size();     
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                if(k != i)
                    for(int j = 0; j < G[i].size(); j++)
                        if(G[i][j] == k)
                            grau[k]++;   
            
        int maior = 0;
        for(int i = 0; i < grau.size(); i++)
            maior = max(maior, grau[i]);    
        
        for(int i = 0; i < grau.size(); i++)
            if(grau[i] == maior)
                res.push_back(i+1);         
        
        cout << "Teste " << caso++ << '\n';
        
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
        
        cout << '\n' << '\n';
        G.clear();
        grau.clear();
        res.clear();
    }
    
    return 0;   
}
