// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Contando Carneirinhos
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1609

#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;
	int t, n, c;
	
	cin >> t;
	while(t--){
		cin >> n;
		while(n--){
			cin >> c;
			s.insert(c);
		}
		cout << s.size() << '\n';
		s.clear();
	}
	
	return 0;
}
