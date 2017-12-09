// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma de Pares Consecutivos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1159

#include <bits/stdc++.h>

using namespace std;

int main(){
	
    int x, p=0, aux;
		
		while(cin >> x &&  x != 0){
			
			if(x%2 == 0){
				p = x;
				for(int i = 2 ; i <= 8; i+=2){
					aux = x+i;
					p += aux;
 				}
			}

			if(x%2 != 0){
				p = x+1;
				x = x+1;
				for(int i = 2 ; i <= 8; i+=2){
					aux = x+i;
					p += aux;
 				}
			}


			cout << p << endl;
		}

}
