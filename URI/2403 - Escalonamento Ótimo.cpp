// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Escalonamento Ótimo
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2403

#include <bits/stdc++.h>
const int MAX = 1e6;

using namespace std;

int n, m, x, y;
vector<int> G[MAX];
int grau[MAX];
vector<int> lista;
priority_queue<int, vector<int>, greater<int> > heap;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        grau[y]++;
        G[x].push_back(y);
    }
    
    for(int i = 0; i < n; i++)
        if(!grau[i])
            heap.push(i);
    
    int sz = 0;
    
    while(!heap.empty()){
        sz++;
        int atual = heap.top();
        heap.pop();
        for(int i = 0; i < G[atual].size(); i++){
            int r = G[atual][i];
            grau[r]--;
            if(!grau[r])
                heap.push(r);
        }
        lista.push_back(atual);
    }
 
    if(sz < n)
        cout << '*' << '\n';
    else
        for(int i = 0; i < n; i++) cout << lista[i] << '\n';
    
     
    return 0;
}
