// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: As Abas de Péricles
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2061

#include <iostream>

using namespace std;

int main (){

	string str;
	int a, casos, c;
	
	cin >> a >> casos;
	c = a;
	while(casos--){
		cin >> str;
		if(str == "fechou")
			c++;
		else
			c--;
	}
	
	cout << c << endl;
	
	return 0;
}
