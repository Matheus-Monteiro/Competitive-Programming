// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fuso Horário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2057

#include <iostream>

using namespace std;

int main(){
	
	int s, t, f, hc;
	
	cin >> s >> t >> f;
	
	hc = s + t + f;
	
	if(hc == 24)
		cout << 0 << endl;
	if(hc < 24)
		if(hc < 0)
			cout << hc + 24 << endl;
		else
			cout << hc << endl;
	if(hc > 24)
		cout << hc - 24 << endl;
	
		
	return 0;
}
