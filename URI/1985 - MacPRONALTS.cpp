// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: MacPRONALTS
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1985

#include <iostream>

using namespace std;

int main(){
	int n, i=0, cod[5], qtd;
	double preco = 0;
	bool t = true;
	
	cin >> n;
	while(n--){
		
	do{
		cin >> cod[i];
		cin >> qtd;
		if(i > 0){
			for(int j = 0; j < i; j++){
			   	if(cod[i] == cod[j])
			   	   	t = false;
				else
					t = true;
			}
		}
	}while(t == false);

		if(cod[i] == 1001)
			preco += 1.5*qtd;
		if(cod[i] == 1002)
			preco += 2.5*qtd;
		if(cod[i] == 1003)
			preco += 3.5*qtd;
		if(cod[i] == 1004)
			preco += 4.5*qtd;
		if(cod[i] == 1005)
			preco += 5.5*qtd;
		i++;
	}
	cout.precision(2);
	cout << fixed;
	cout << preco << endl;

	   
return 0;
}

