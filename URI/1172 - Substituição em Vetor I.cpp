// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Substituição em Vetor I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1172

#include <iostream>
 using namespace std;
int main()
{
    int v[10];
    
        for(int i=0; i<10; i++){
            cin >> v[i];
        }
        
        for(int i=0; i<10; i++){
            if(v[i]<=0){
                cout << "X[" << i << "] = 1" << endl;
            }else{
                cout << "X[" << i << "] = " << v[i] << endl; 
            }
        }

        
    return(0);
}

