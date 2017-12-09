// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Escolhido
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1983

#include <iostream>

using namespace std;

int main(){
	int n, matricula[1000100], tmp = 0;
	double nota[110], aux;
	cin >> n;

		for(int i = 0; i < n; i++){
			cin >> matricula[i] >> nota[i];
		}
		aux = nota[0];
		for(int i = 0; i < n; i++){
			if(aux < nota[i]){
				aux = nota[i];
				tmp = i;
			}
		}
		if(aux >= 8)
			cout << matricula[tmp] << endl;
		else
			cout << "Minimum note not reached" << endl;
return 0;
}
