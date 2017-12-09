// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Matriz Quadrada III
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1557

#include <bits/stdc++.h>
#define MAX 110

using namespace std;

int main(){
    int matriz[MAX][MAX], n;

    while(cin >> n && n != 0){
        
        int aux = 1, c = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matriz[i][j] = aux;
                aux = 2*aux;            
            }
            aux = 2*c;
            c = aux;
        }
        
        int nMaior = matriz[n-1][n-1], contagem = 0;
      
        while(nMaior>0){
            nMaior /= 10;
            contagem++;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int atual = matriz[i][j], cont = 0, k;
               
                while(atual>0){
                    atual /= 10;
                     cont++;
                }

                if(j>0) {
                    for(k = 0; k < contagem+1 - cont; k++)
                        printf(" ");
                    
                }else{
                    for(k = 0; k < contagem - cont; k++)
                        printf(" ");
                   
                }
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    
    return 0;
}
