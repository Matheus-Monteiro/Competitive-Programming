// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Blobs
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1170

#include <iostream>

using namespace std;

int main(){
	
	int n, contador;
	double c;
	cin >> n;
	while(n--){
		cin >> c;
		contador = 0;
		while(c > 1){
			c /= 2;
			contador++;
		}
		cout << contador << " dias" << endl;
	}
	
	return 0;
}	
