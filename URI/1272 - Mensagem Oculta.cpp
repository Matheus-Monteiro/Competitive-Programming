// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Mensagem Oculta
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1272

#include <iostream>

using namespace std;

int main(){
	string str, resposta;
	int n;
	
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, str);
		if(str[0] != ' ')
	   	   	resposta.push_back(str[0]);
		for(int i = 0; i < str.length()-1; i++){
			if(str[i] == ' ')
				if(str[i+1] != ' ')
					resposta.push_back(str[i+1]);
		}
		cout << resposta << endl;
		str.clear();
		resposta.clear();
	}
	return 0;
}
