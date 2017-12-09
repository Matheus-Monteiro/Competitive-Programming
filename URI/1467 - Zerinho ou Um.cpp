// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Zerinho ou Um
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1467

#include <iostream>

using namespace std;

int main(){
	
	int v[3];
	
	while(cin >> v[0] >> v[1] >> v[2]){
		if(v[0] == v[1] && v[1] == v[2] && v[1] == 0 || v[0] == v[1] && v[1] == v[2] && v[1] == 1)
			cout << "*" << endl;
		if(v[0] == v[1] && v[0] == 1 && v[2] == 0)
			cout << "C" << endl;
		if(v[0] == v[2] && v[0] == 1 && v[1] == 0)
			cout << "B" << endl;
		if(v[1] == v[2] && v[1] == 1 && v[0] == 0)
			cout << "A" << endl;
		if(v[0] == v[1] && v[1] == 0 && v[2] == 1)
			cout << "C" << endl;
		if(v[0] == v[2] && v[0] == 0 && v[1] == 1)
			cout << "B" << endl;
		if(v[1] == v[2] && v[1] == 0 && v[0] == 1)
			cout << "A" << endl;
		
	}
	
	return 0;
}
