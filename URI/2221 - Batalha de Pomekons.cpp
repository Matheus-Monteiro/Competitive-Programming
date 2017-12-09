// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Batalha de Pomekons
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2221

#include <iostream>	

using namespace std;

int main(){

	int t, b, a1, d1, l1, a2, d2, l2, golpe1, golpe2;
	
	cin >> t;
	
	while(t--){
		cin >> b >> a1 >> d1 >> l1 >> a2 >> d2 >> l2;
		if(l1%2 == 0)
		 	golpe1 = ((a1 + d1)/2)+b;
		else
			golpe1 = (a1 + d1)/2;
		
		if(l2%2 == 0)
			golpe2 = ((a2 + d2)/2)+b;
		else
			golpe2 = (a2 + d2)/2;
			
		if(golpe1 > golpe2)
			cout << "Dabriel" << endl;
		if(golpe1 < golpe2)
			cout << "Guarte" << endl;
		if(golpe1 == golpe2)
			cout << "Empate" << endl;
	}

	return 0;
}
