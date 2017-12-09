// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Getline One
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1216

#include <iostream>

using namespace std;

int main(){
	
	string nome;
	double n, cont = 1, soma_anter = 0;
	double distancia_m_p = 0.0;
	
	while(getline(cin, nome)){
		cin >> n;
		cin.ignore();
		distancia_m_p = (soma_anter + n)/cont;
		soma_anter += n;
		cont++;
	}
	cout.precision(1);
	cout << fixed << distancia_m_p << endl;
	return 0;
}
