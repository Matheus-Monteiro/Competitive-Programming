// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequência de Números e Soma
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1101

#include <iostream>

using namespace std;

int main(){

    int x=1, y=1, sum=0, nu;

        while(x!=0 || y!=0 || x>0 || y>0){

            cin >> x >> y;
            
            if(x==0 || y==0 || x<0 || y<0)
                return 0;
                            
                            
            if(x>y){
                int tmp = y;
                    y = x;
                    x = tmp;
            }
            
            for(int i=0; i<=y-x; i++){
                nu = x+i;
                cout << nu << " ";
                sum += nu; 
            }
            
            cout << "Sum=" << sum << endl;      
            
            sum=0;         
        }
}
