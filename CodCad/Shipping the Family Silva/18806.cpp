#include <bits/stdc++.h>
const int MAX = 1e4;
const int INFINITO = 1e7;

using namespace std;
typedef pair<int,int> pii;

int n, m;
int distancia[MAX], processado[MAX];
vector<pii> G[MAX];

int prim(){
    for(int i = 2; i <= n; i++)
        distancia[i] = INFINITO;
    distancia[1] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    
    fila.push({0, 1});
    
    while(true){
        int davez = -1;
        while(!fila.empty()){
            int atual = fila.top().second;
            fila.pop();
            if(!processado[atual]){
                davez = atual;
                break;
            }
        }
        if(davez == -1)
            break;
        processado[davez] = 1;
        
        for(int i = 0; i < G[davez].size(); i++){
            int dist = G[davez][i].first;
            int atual = G[davez][i].second;
            if(distancia[atual] > dist and !processado[atual]){
                distancia[atual] = dist;
                fila.push({distancia[atual], atual});
            }
        }
    }
    int custo_arvore = 0;
    for(int i = 1; i <= n; i++)
        custo_arvore += distancia[i];
    return custo_arvore;
}

int main(){
    int x, y, d;
    
    cin >> n >> m;    
       
    while(m--){
        cin >> x >> y >> d;
        G[x+1].push_back({d, y+1});
        G[y+1].push_back({d, x+1});
    }  
       
    cout << prim() << '\n';
       
    return 0;
}