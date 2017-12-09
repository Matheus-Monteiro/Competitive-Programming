// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Lista Telefônica Econômica
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1211

#include <iostream>
#include <queue>

using namespace std;

int main(){

	priority_queue<string , vector<string>, greater<string> > fila;
	
	int x;
	string n;
	while(cin >> x){
		while(x--){
			cin >> n;
			fila.push(n);
		}
		string str1, str2;
		str1 = fila.top();
		fila.pop();
		int c = 0;
		while(!fila.empty()){					
			str2 = fila.top();
			fila.pop();
			for( int i = 0 ; i < str1.length() ; i++ ){
				if( str1[i] == str2[i] )
					c++;
				else
					break;
			}
			str1 = str2;
		}
		cout << c << endl;
	}
	return(0);
}
