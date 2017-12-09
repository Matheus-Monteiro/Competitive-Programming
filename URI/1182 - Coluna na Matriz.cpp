// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Coluna na Matriz
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1182

#include <iostream>

using namespace std;

int main(){
	double m[12][12], soma=0;
	int aux, col;
	char o;
	
	cin >> col >> o;

    for(int i = 0; i < 12; i++){
    	for(int j = 0; j < 12; j++){
    		cin >> m[i][j];
    	}
    }
    for(int i = 0; i < 12; i++){
    	for(int j = 0; j < 12; j++){
    		aux = i+j;
    		if(col == j)
    			soma += m[i][j];
    	}
    }
    cout.precision(1);
    cout << fixed;
    if(o == 'S')
    	cout << soma << endl;
    if(o == 'M')
    	cout << soma/12 << endl;
    
    
return 0;
}
