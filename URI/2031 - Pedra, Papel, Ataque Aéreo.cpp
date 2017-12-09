// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pedra, Papel, Ataque Aéreo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2031

#include <iostream>

using namespace std;

int main(){

	int n;
	string str1, str2;
	
	cin >> n;
	
	while(n--){
		cin >> str1 >> str2;
		
		if(str1 == "ataque" && str2 != "ataque")
			cout << "Jogador 1 venceu" << endl;
		if(str1 != "ataque" && str2 == "ataque")
			cout << "Jogador 2 venceu" << endl;
		if(str1 == "pedra" && str2 == "papel")
			cout << "Jogador 1 venceu" << endl;
		if(str1 == "papel" && str2 == "pedra")
			cout << "Jogador 2 venceu" << endl;
		if(str1 == "papel" && str2 == "papel")
			cout << "Ambos venceram" << endl;
		if(str1 == "pedra" && str2 == "pedra")
			cout << "Sem ganhador" << endl;
		if(str1 == "ataque" && str2 == "ataque")
			cout << "Aniquilacao mutua" << endl;		
	}

return 0;
}
