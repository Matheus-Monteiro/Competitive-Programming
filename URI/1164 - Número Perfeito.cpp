// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Número Perfeito
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1164

#include <iostream>

using namespace std;

int main(){

	int n, x, r;
	
		cin >> n;
		
		while(n--){
			r=0;
			cin >> x;
			
				for(int i=1; i<x; i++){
					if(x%i==0){
						r+=i;
					}
				}
				
				if(r==x){
					cout << x << " eh perfeito" << endl;
				}else{
					cout << x << " nao eh perfeito" << endl;
				}
				
		}
}
