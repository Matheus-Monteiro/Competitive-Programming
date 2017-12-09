// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Duas Notas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2140

#include <iostream>
#include <vector>

using namespace std;

bool troco(int n, int m, vector<int> cedula){
	int valor = m - n;
	int qtNotas = 0, aux;

	for(int i = cedula.size()-1; i >= 0; i--){
		qtNotas += valor/cedula[i];
		aux = valor/cedula[i];
		valor -= aux*cedula[i];
	}

	if(qtNotas == 2)
		return true;
	else 
		return false;
}

int main(){
	
	int n, m;
	bool teste;
	vector<int> cedula;
	
	cedula.push_back(2);
	cedula.push_back(5);
	cedula.push_back(10);
	cedula.push_back(20);
	cedula.push_back(50);
	cedula.push_back(100);
	
	while((cin >> n >> m), n, m){
		
		teste = troco(n, m, cedula);
		if(teste)
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;
	}	
	return 0;
}
