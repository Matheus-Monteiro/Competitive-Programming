// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Corrida de Lesmas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1789

#include <iostream>

using namespace std;

int main(){
   int L, aux, v[501] = {0};
	

	while(cin >> L){

		for(int i = 0; i < L; i++){
 			cin >> v[i];
		}
		aux = v[0];
		for(int i = 0; i < L-1; i++){
			if(aux < v[i+1])	
				aux = v[i+1];
		} 

		if(aux < 10)
			cout << "1" << endl;
		if(aux >= 10 && aux < 20)
			cout << "2" << endl;
		if(aux >= 20)
			cout << "3" << endl;
		for(int i = 0; i < L; i++){
			v[i] = 0;		
		}
	}
}
