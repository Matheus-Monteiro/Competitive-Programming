// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: LED
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1168

#include <iostream>

using namespace std;

int main(){

	string numero;
	int qtdLeds, n;
	cin >> n;
	while(n--){
		qtdLeds = 0;
		cin >> numero;
		for(int i = 0; i < numero.length(); i++){
			if(numero[i] == '1')	
				qtdLeds += 2;
			if(numero[i] == '2')	
				qtdLeds += 5;
			if(numero[i] == '3')	
				qtdLeds += 5;
			if(numero[i] == '4')	
				qtdLeds += 4;
			if(numero[i] == '5')	
				qtdLeds += 5;
			if(numero[i] == '6')	
				qtdLeds += 6;
			if(numero[i] == '7')	
				qtdLeds += 3;
			if(numero[i] == '8')	
				qtdLeds += 7;
			if(numero[i] == '9')	
				qtdLeds += 6;
			if(numero[i] == '0')	
				qtdLeds += 6;
		}
		cout << qtdLeds << " leds" << endl;
	}

return 0;
}
