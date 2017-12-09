// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogo do Maior
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1397

#include <iostream>

using namespace std;

int main(){
	
	int n;
	int a, b, j1, j2;
	
	while(cin >> n && n != 0){
		j1 = j2 = 0;
		while(n--){
			cin >> a >> b;
			if(a > b)
				j1++;
			if(a < b)
				j2++;
		}
		cout << j1 << " " << j2 << endl;
	}
	
	return 0;
}
