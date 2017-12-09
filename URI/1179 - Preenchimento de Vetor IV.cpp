// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Preenchimento de Vetor IV
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1179

#include <iostream>

using namespace std;

int main (){

    int par[5], im[5], cp = 0, ci = 0;

    for( int i = 0 ; i < 15 ; i++ ){
        int x;
        cin >> x;
        if( x%2 == 0 ){
            par[cp] = x;
            cp++;
        }else{
            im[ci] = x;
            ci++;
        }
        if(cp == 5){
            for( int i = 0 ; i < 5 ; i++ )
                cout << "par[" << i << "] = " << par[i] << endl;
            cp = 0;
        }
        if(ci == 5){
            for( int i = 0 ; i < 5 ; i++ )
                cout << "impar[" << i << "] = " << im[i] << endl;
            ci = 0;
        }
    }
    for(int i = 0 ; i < ci ; i++ )
        cout << "impar[" << i << "] = " << im[i] << endl;
    for(int i = 0 ; i < cp ; i++ )
        cout << "par[" << i << "] = " << par[i] << endl;

	return 0;
}
