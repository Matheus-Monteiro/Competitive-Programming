// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Huaauhahhuahau
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2242

#include <iostream>

using namespace std;

int main(){

	string str, risada;
	
	cin >> str;
	risada = str;
	
	int j = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
			risada[j] = str[i];
			j++;
		}
	}
	string aux;
	aux = str;
	int m = j-1;
	for(int i = 0; i < j; i++){
		aux[i] = risada[m];
		m--;
	}
	bool buraco;
	for(int i = 0; i < j; i++){
		if(aux[i] == risada[i])
			buraco = true;
		else{
			buraco = false;
			break;
		}
		
	}
	if(buraco)
		cout << "S" << endl;
	else 
		cout << "N" << endl;
	return 0;
}
