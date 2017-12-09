// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cara ou Coroa
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1329

#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int t, n, x, y;
	
	while((cin >> t),t){
		x = 0;
		y = 0;
		while(t--){
			cin >> n;
			if(n == 0)
				x++;
			else 
				y++;	
		}
		cout << "Mary won "<< x << " times and John won " << y << " times" << endl;
	}
	
	return 0;
}
