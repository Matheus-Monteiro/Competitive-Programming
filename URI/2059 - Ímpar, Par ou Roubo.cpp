// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ímpar, Par ou Roubo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2059

#include <iostream>

using namespace std;

int main (){

	int p, j1, j2, r, a;
	
	cin >> p >> j1 >> j2 >> r >> a;
	
	if(r == 1 && a == 1)
		cout << "Jogador 2 ganha!" << endl;
	if(r == 1 && a == 0)
		cout << "Jogador 1 ganha!" << endl;
	if(r == 0 && a == 1)
		cout << "Jogador 1 ganha!" << endl;
		
	if(r == 0 && a == 0){
		if(p == 1){
			if((j1 + j2)%2 == 0)
				cout << "Jogador 1 ganha!" << endl;
			else
				cout << "Jogador 2 ganha!" << endl;
		}else{
			if((j1 + j2)%2 != 0)
				cout << "Jogador 1 ganha!" << endl;
			else
				cout << "Jogador 2 ganha!" << endl;
		}
	}
	
	return 0;
}
