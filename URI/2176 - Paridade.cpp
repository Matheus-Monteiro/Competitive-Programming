// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Paridade
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2176

#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	int cont=0;
	
	cin >> str;
	
	for(int i = 0; i < str.size(); i++)
		if(str[i] == '1')
			cont++;
	
	if(cont%2 == 0)
		str = str + '0';
	else
		str = str + '1';
		
	cout << str << endl;
	
	return 0;	
}
