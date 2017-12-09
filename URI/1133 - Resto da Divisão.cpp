// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Resto da Divisão
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1133

#include <iostream>

using namespace std;

int main()
{
    int x, y, aux=0;

        cin >> x >> y;

        if(x > y){
            for(int i=1; i<x-y; i++){
                aux = y+i;
                if(aux%5 == 2 || aux%5 == 3){
                    cout << aux << endl;
                }
            }
        }

        if(x < y){
            for(int i=1; i<y-x; i++){
                aux = x+i;
                if(aux%5 == 2 || aux%5 == 3){
                    cout << aux << endl;
                }
            }
        }
    return 0;
}
