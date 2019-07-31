#include <iostream>
#define MAXN 100100

using namespace std;

int n, m;
int faixa[MAXN];
int ponto[MAXN];
int forca[MAXN];

int buscab(int x){
    int ini = 1, fim = n-1, meio;
    
    while(ini <= fim){
        meio = (ini + fim)/2;
        
        if(faixa[meio] == x)
            return meio;
        if(faixa[meio] < x)
            ini = meio + 1;
        if(faixa[meio] > x)
            fim = meio - 1;
    }
    return meio;
}


int main(){
    cin >> n >> m;
    
    faixa[0] = 0;
    for(int i = 1; i <= n-1; i++)
        cin >> faixa[i];
   
    for(int i = 1; i <= n; i++)
        cin >> ponto[i];
        
    for(int i = 1; i <= m; i++)
        cin >> forca[i];
        
    int aux = buscab(3);
    
    for(int i = 1, j = 0; i <= m; i++){
        aux = buscab(forca[i]);
        if(forca[i] >= faixa[aux-1] and forca[i] < faixa[aux])
            cout << ponto[aux];
        else
            cout << ponto[aux+1];
        if(i < m)
            cout << " ";
    }
    cout << endl;

	return 0;
}

