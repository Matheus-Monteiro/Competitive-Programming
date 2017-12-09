// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: De Dentro para Fora
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1235

#include <iostream>
#include <string>

using namespace std;

int main(){

	string str, aux1;
	int n, tam;
	
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, str);
		
		aux1 = str;
		int j = 0;
		for(int i = (str.size()-1)/2; i > -1; i--){
			aux1[j] = str[i];
			j++;
		}
		for(int i = str.size()-1; i > (str.size()-1)/2; i--){
			aux1[j] = str[i];
			j++;
		}
		cout << aux1 << endl;
	}
	return 0;
}
