// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dividindo X por Y
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1116

#include <iostream>

using namespace std;

int main(){

    int n, x, y;
    double r;
        
        cin >> n;
        
        while(n--){
        
            cin >> x >> y;
            
            if(y!=0){
                r = (double (x)/y);
                
                cout.precision(1);
                cout << fixed;
                cout << r << endl;
            }else{
                cout << "divisao impossivel" << endl;
            }
            
        }
}
