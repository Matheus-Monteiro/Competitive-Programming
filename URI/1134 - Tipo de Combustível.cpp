// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tipo de Combustível
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1134

#include <iostream>

using namespace std;

int main(){

    int c=0, a=0, d=0, g=0;
   
        
        while(c!=4){
            
            do{
                cin >> c;
            }while(c<1 || c>4);
            
            if(c==4)
                break;
            
            if(c==1){
                a+=1;
            }
            
            if(c==2){
                g+=1;
            }
            
            if(c==3){
                d+=1;
            }
        }
        
            cout << "MUITO OBRIGADO" << endl;
            cout << "Alcool: " << a << endl;
            cout << "Gasolina: " << g << endl;
            cout << "Diesel: " << d << endl;
}
