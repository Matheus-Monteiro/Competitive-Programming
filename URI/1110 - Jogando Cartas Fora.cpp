// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogando Cartas Fora
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1110

#include <iostream>
#include <queue>

using namespace std;

int main (){
	
	queue<int> fila;
	int n;
	
	while((cin >> n) ,n){
		for( int i = 1 ; i <= n ; i++ ){
			fila.push(i);
		}
		cout << "Discarded cards: ";
		while(fila.size() > 1){
			cout << fila.front();
			if(fila.size() > 2)
				cout << ", ";	
			fila.pop();
			int aux = fila.front();
			fila.pop();
			fila.push(aux);
		}
		cout << endl;
		cout << "Remaining card: " << fila.front() <<endl;
		while(!fila.empty())
			fila.pop();
		
	}
	return 0;
}
