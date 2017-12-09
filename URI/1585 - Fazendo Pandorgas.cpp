// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fazendo Pandorgas
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1585

#include <iostream>

using namespace std;

int main(){
	int n, x, y, res;
	
	cin >> n;
	
	while(n--){
		cin >> x >> y;
		res = (x*y)/2;
		cout << res << " cm2" << endl;
	}
		
	return 0;
}
