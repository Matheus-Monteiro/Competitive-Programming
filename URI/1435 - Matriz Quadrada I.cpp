// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Matriz Quadrada I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1435

#include <bits/stdc++.h>
#define MAX 110

using namespace std;

int main(){
    int matriz[MAX][MAX], n;
    
    while(cin >> n && n != 0){
        
        int ini = 0;
        int fim = n-1;
        int cont = 1;
        
        for(int i = 0; i < (n+1)/ 2; i++){
            for(int j = ini; j <= fim; j++){
                matriz[j][ini] = cont;
                matriz[ini][j] = cont;
                matriz[j][fim] = cont;
                matriz[fim][j] = cont;
            }
            cont++;
            ini++;
            fim--;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == n-1){
                    printf("%3d", matriz[i][j]);
                    printf("\n");    
                }else{
                    printf("%3d ", matriz[i][j]);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
