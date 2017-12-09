// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Conta
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1866

#include <iostream>

using namespace std;

int main(){
   int n, caso;
   
		cin >> caso;
		while(caso--){
			cin >> n;
			if(n%2 == 0)
				cout << "0" << endl;
			else
				cout << "1" << endl;
		}
return(0);
}
