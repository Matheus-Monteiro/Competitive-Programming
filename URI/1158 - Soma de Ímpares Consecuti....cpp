// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma de Ímpares Consecuti...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1158

#include<iostream>

using namespace std;

int main(){

    int n, x, y, soma=0;

    cin >> n;

    while(n--){
        cin >> x >> y;

        if(x%2 == 0){
                int tmp = x+1;
                soma = tmp;
            for(int i = 2; i < 2*y; i+=2){
                int aux = tmp + i;
                soma += aux;
            }
        }

        if(x%2 != 0){
                soma = x;
            for(int i = 2; i < 2*y; i+=2){
                int aux = x + i;
                soma += aux;
            }
        }
        cout << soma << endl;
    }

}

