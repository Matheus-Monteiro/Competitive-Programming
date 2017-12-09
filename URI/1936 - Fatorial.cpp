// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fatorial
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1936

#include <iostream>

using namespace std;

int fatorial(int n){
	int i = 1;
	for(int j = n; j > 0; j--){
		i *= j;
	}
	return i;
}

int main(){

	int x, aux, c=0, z=0, t;
	
	cin >> x;
	
	for(int i = 1; i < x; i++){
		fatorial(i);
		if(fatorial(i) >= x){
			aux = i-1;
			break;
		}
	}
	for(int i = aux; i >= 1; i--){
		do{
			t = z+fatorial(i);
			if(t <= x){
				z += fatorial(i);
				c++;
			}
		}while(t <= x);
		if(z >= x)
			break;
	}
	cout << c << endl;

return 0;
}
