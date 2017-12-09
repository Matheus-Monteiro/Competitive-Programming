// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Roberto e a Sala Desenfreada
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1953

#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, nm, x=0, y=0, aux;
	string cur;
	

		while(cin >> n){
		aux = n;
			while(n--){
			
				cin >> nm >> cur;
			
				if(cur == "EPR"){
					x+=1;	
				}
			
				if(cur == "EHD" ){
					y+=1;	
				}
			
			
			}
				cout << "EPR: " << x << endl;
				cout << "EHD: " << y << endl;
				cout << "INTRUSOS: " << aux-x-y << endl;
				
				x=0; y=0;
		}

	return 0;
}
