// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: TDA Racional
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1022

#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    return (b == 0 ? a : mdc(b, a%b));
}

int main(){
    int t, x1, x2, y1, y2, x, y;
    char o, b;
    
    cin >> t;
    
    while(t--){
        cin >> x1 >> b >> x2 >> o >> y1 >> b >> y2;   
        if(o == '+'){
            x = x1*y2 + x2*y1;
            y = x2*y2;
        }else{
            if(o == '-'){
                x = x1*y2 - x2*y1;
                y = x2*y2;
            }else{
                if(o == '*'){
                    x = x1*y1;
                    y = x2*y2;
                }else{
                    x = x1*y2;
                    y = x2*y1;
                }
            }
        }
        int m = mdc(x,y);
        cout << x << '/' << y << " = ";
        if((y/m) < 0 and (x/m) > 0 or (y/m) < 0 and (x/m) < 0)
            cout << -x/m << '/' << -y/m << '\n';
        else
            cout << x/m << '/' << y/m << '\n';
    }   
    return 0;
}
