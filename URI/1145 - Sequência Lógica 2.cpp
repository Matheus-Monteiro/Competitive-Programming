// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequência Lógica 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1145

#include <iostream>

using namespace std;

int main()
{
    int x, y, a=0;
   
        cin >> x >> y;  
           while(a!=y){
           
              for(int i=0; i<x; i++){
                if(i<x-1){
                  cout << a+1 << " " ;
                }else{
                  if(i==x-1)
                  cout << a+1;
                }
                a++;
              }
              cout << "\n";
           }

    return 0;
}
