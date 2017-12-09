// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Botas Perdidas
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1245

#include <iostream>

using namespace std;

int main(){

    char c;
    int dir[31] , esq[31], x, k;
    while(cin >> x){
        for( int i = 0 ; i < 31 ; i++ ){
            dir[i] = 0;
            esq[i] = 0;
        }
        while(x--){
            cin >> k >> c;
            if( c == 'D' )
                dir[k-30] += 1;
            else
                esq[k-30] += 1;
        }
        int c = 0;
        for( int i = 0 ; i < 31 ; i++ ){
            if( dir[i] >= esq[i] )
                c += esq[i];
            else
                c += dir[i];
        }
        cout << c << endl;
    }

    return 0;
}
