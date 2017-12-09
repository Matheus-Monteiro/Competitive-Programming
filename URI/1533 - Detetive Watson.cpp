// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Detetive Watson
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1533

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v[1010], num, v2[1010];
	
	while(cin >> n && n != 0){
		for(int i = 0; i < n; i++)
			cin >> v[i];
		for(int i = 0; i < n; i++)
			v2[i] = v[i];
		
		sort(v, v+n);
		
		num = v[n-2];
		
		for(int i = 0; i < n; i++){
			if(num == v2[i]){
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
