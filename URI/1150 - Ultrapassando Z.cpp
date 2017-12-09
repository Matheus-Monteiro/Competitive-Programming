// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ultrapassando Z
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1150

#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, z , s=0, v=0, a;

	while(cin >> x >> z){

		if(z <= x){
			do{
				cin >> z;
			}while(z <= x);
		}

		if(x<0 && z<0){
			for(int i = 0 ; i <= 2*abs(x) ; i++){
				if(s <= z+1){
					a = x+i;		
					s += a;
					v += 1;
				}
			}
		}else{

			for(int i = 0 ; i <= x+z ; i++){
				if(s <= z+1){
					a = x+i;		
					s += a;
					v += 1;
				}
			}
		}
		cout << v << endl;
		s=0;
		v=0;
	}	

		
return 0;
}
