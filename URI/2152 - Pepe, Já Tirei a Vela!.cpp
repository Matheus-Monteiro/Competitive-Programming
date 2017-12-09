// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pepe, Já Tirei a Vela!
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2152

#include <iostream>

using namespace std;

int main(){
	
	int n, c = 0;
	string h, m;
	
	cin >> n;
	
	while(n--){
		cin >> h >> m >> c;
		
		if(h.size() == 1)
			cout << "0" << h << ":";
		if(h.size() == 2)
			cout << h << ":";
		if(m.size() == 1)
			cout << "0" << m;
		if(m.size() == 2)
			cout << m;
		
		if(c == 1)
			cout << " - A porta abriu!" << endl;
        if(c == 0)
         	cout << " - A porta fechou!" << endl;
	}
	
	return 0;
}
