// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Natal de Pedrinho
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2139

#include <iostream>

using namespace std;

int main(){
	
	int m, d, x, mes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 25};
	
	while(cin >> m >> d){
		if(m == 12 && d == 25)
		   	cout << "E natal!" << endl;
		if(m == 12 && d == 24)
			cout << "E vespera de natal!" << endl;
		if(m == 12 && d > 25)
			cout << "Ja passou!" << endl;   
		if(m == 12 && d < 24 || m < 12){
			mes[m] -= d;
			x = 0;
			for(int i = m-1; i < 12; i++){
				x += mes[i];
			}
			cout << "Faltam " << x << " dias para o natal!" << endl;
			mes[m] += d;
		}
	}
	
	return 0;
}
