// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Lendo Livros
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1542

#include <iostream>

using namespace std;

int main(){
	
	int q, d, p, n;

	while((cin >> q),q){
		cin >> d >> p;
		n = (q*p*d)/(p-q);
		if(n == 1)
			cout << n << " pagina" << endl;
		if(n > 1)
			cout << n << " paginas" << endl;
	}
	
	return 0;
}
