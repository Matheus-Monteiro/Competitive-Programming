// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Just in Time
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2353

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int n, num;
	bool ok, ok2;
	
	cin >> n;
	
	ok2 = true;
	for(int i = n; i > 1 and ok2; i--){
		ok = true;
		for(int j = 2; j < sqrt(i) and ok; j++){
			if(i%j == 0)
				ok = false;
		}
		if(ok){
			num = i;
			ok2 = false;
		}
	}
	cout << num << endl;

	return 0;
}
