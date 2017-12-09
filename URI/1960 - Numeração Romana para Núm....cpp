// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Numeração Romana para Núm...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1960

#include <iostream>

using namespace std;

int main(){

	int numero, n;
	
	string centenas[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	string dezenas[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	string unidades[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	
	cin >> numero;
	
	n = numero/100;
	
	switch(n){
		case 1 : cout << centenas[0];
			break;
		case 2 : cout << centenas[1];
			break;
		case 3 : cout << centenas[2];
			break;
		case 4 : cout << centenas[3];
			break;
		case 5 : cout << centenas[4];
			break;
		case 6 : cout << centenas[5];
			break;
		case 7 : cout << centenas[6];
			break;
		case 8 : cout << centenas[7];
			break;
		case 9 : cout << centenas[8];
			break;	
	}
	
	
	numero = numero%100;
	n = numero/10;
	
	switch(n){
		case 1 : cout << dezenas[0];
			break;
		case 2 : cout << dezenas[1];
			break;
		case 3 : cout << dezenas[2];
			break;
		case 4 : cout << dezenas[3];
			break;
		case 5 : cout << dezenas[4];
			break;
		case 6 : cout << dezenas[5];
			break;
		case 7 : cout << dezenas[6];
			break;
		case 8 : cout << dezenas[7];
			break;
		case 9 : cout << dezenas[8];
			break;
	}
	
	numero = numero%10;
	n = numero/1;
	
	switch(n){
		case 1 : cout << unidades[0];
			break;
		case 2 : cout << unidades[1];
			break;
		case 3 : cout << unidades[2];
			break;
		case 4 : cout << unidades[3];
			break;
		case 5 : cout << unidades[4];
			break;
		case 6 : cout << unidades[5];
			break;
		case 7 : cout << unidades[6];
			break;
		case 8 : cout << unidades[7];
			break;
		case 9 : cout << unidades[8];
			break;
	}
	cout << endl;
	return 0;
}
