// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Leitura Ótica
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1129

#include <iostream>

using namespace std;

int main(){
	
	
	int n, resposta[5], aux, posicao;
	
	while((cin >> n) ,n){
		while(n--){
			aux=0;
			for(int i = 0; i < 5; i++)
				cin >> resposta[i];
		
			for(int i = 0; i < 5; i++){
				if(resposta[i] <= 127){
					aux++;
					posicao = i;
				}
			}
			if(aux > 1 || aux == 0)
				cout << "*" << endl;
			else{
				if(posicao == 0)
					cout << "A" << endl;
				if(posicao == 1)
					cout << "B" << endl;
				if(posicao == 2)
					cout << "C" << endl;
				if(posicao == 3)
					cout << "D" << endl;
				if(posicao == 4)
					cout << "E" << endl;
			}
		}
	}
return 0;
}
