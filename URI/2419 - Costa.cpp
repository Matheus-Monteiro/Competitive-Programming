// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Costa
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2419

#include <bits/stdc++.h>
const int MAX = 1005;

using namespace std;

char mapa[MAX][MAX];
int n, m;

bool teste(int i, int j){
    if(mapa[i][j] == '#' and (i+1 == n or j+1 == m or i-1 == -1 or j-1 == -1))
        return true;
    else
        if(mapa[i][j] == '#' and (mapa[i+1][j] == '.' or mapa[i-1][j] == '.' or mapa[i][j+1] == '.' or mapa[i][j-1] == '.'))
            return true;
        else
            return false;
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> mapa[i];
    
    int cont = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(teste(i, j))
                cont++;
    cout << cont << '\n';
    
    return 0;
}
