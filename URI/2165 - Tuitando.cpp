// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tuitando
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2165

#include <iostream>
#include <string>

using namespace std;

int main () {
	
	string str;
	
	getline(cin, str);

	if(str.length() <= 140)
		cout << "TWEET" << endl;
	if(str.length() > 140)
		cout << "MUTE" << endl;
	
	return 0;
}
