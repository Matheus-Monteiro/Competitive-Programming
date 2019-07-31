#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;  

#define MAXN 10100
#define INFINITO 999999999

int n, m;                                 
int distancia[MAXN];          
int processado[MAXN];        
vector<pii> vizinhos[MAXN];    

void Dijkstra(int S){
	
	for(int i = 1;i <= n;i++) distancia[i] = INFINITO;
	distancia[S] = 0;                                 
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; 
	fila.push( pii(distancia[S], S) );                    

	while(true){ 
		
		int davez = -1;
		int menor = INFINITO;
		
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){
				davez = atual;
				break;
			}
		}
		
		if(davez == -1) break;
		
		processado[davez] = true;
		
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
		
			if( distancia[atual] > distancia[davez] + dist ){
				distancia[atual] = distancia[davez] + dist; 
				fila.push( pii(distancia[atual], atual) );  
			}
		}
	}
	
}

int main(){
	
	cin >> n >> m;
	int aux_n = n;
	n = 2*n;
	
	for(int i = 1;i <= m;i++){
		
		int x, y, tempo;
		cin >> x >> y >> tempo;
		
		vizinhos[x].push_back( pii(tempo, y) );
		vizinhos[y].push_back( pii(tempo, x) );
	}
	
	Dijkstra(0);
	cout << distancia[aux_n+1] << endl;
	
	return 0;
}