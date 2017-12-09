// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Crescimento Populacional
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1160

#include<iostream>

using namespace std;

int main(){

    int t, pa, pb, anos = 0;
    double g1, g2;

    cin >> t;

    while(t--){
        cin >> pa >> pb >> g1 >> g2;

        while(pa <= pb){
            pa = pa + (pa*(g1/100.0));
            pb = pb + (pb*(g2/100.0));
            anos += 1;

            if(anos > 100){
                cout << "Mais de 1 seculo." << endl;
                break;
            }
        }
        if(anos <= 100)
            cout << anos << " anos." << endl;

        anos = 0;
    }
}

