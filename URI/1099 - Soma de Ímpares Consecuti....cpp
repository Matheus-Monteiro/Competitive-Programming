// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma de Ímpares Consecuti...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1099

#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int n, x, y, s=0, nu;


        cin >> n;

        while(n--){

            cin >> x >> y;
                            
                if(x>y){
                    int tmp = x;
                         x = y;
                         y = tmp;
                 }
                  

                if(x%2==0 && y%2!=0  || x%2==0 && y%2==0 || x%2!=0 && y%2!=0 || x%2!=0 && y%2==0){
                    for(int i=1; i<y-x; i++){
                        nu = x+i;
                   
                        if(nu%2!=0){
                            s += nu;
                        }
                    }
                    
                      cout << s << endl;
                }
               
                s=0;
                
        }
}
