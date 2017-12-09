// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Um-Dois-Três
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1332

#include <iostream>
#include <string>

using namespace std;

int main(){

	string str;
	int n;
	cin >> n;
	while(n--){
		cin >> str;
	
		if(str.size() == 3){
			if(str[0] == 'o' && str[1] == 'n' || str[0] == 'o' && str[2] == 'e' || str[1] == 'n' && str[2] == 'e')
				cout << "1" << endl;
			if(str[0] == 't' && str[1] == 'w' || str[1] == 'w' && str[2] == 'o' || str[0] == 't' && str[2] == 'o')
				cout << "2" << endl;
		}else{
			cout << "3" << endl;
		}
	}
	
	return 0;
}
