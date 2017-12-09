// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Frequência de Letras
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1255

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, f[26], maior = 0, k;
	vector<int> letters;
	string str; 
	char resposta;
	
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, str);
		memset(f, 0, sizeof(f));
		for(int i = 0; i < str.size(); i++){
			if(isupper(str[i]))
				f[(int)str[i]-65]++;
			if(islower(str[i]))
				f[(int)str[i]-97]++;
		}
		for(int i = 0; i < 26; i++){
			if(f[i] > maior){
				maior = f[i];
				k = i;
			}
		}
		f[k] = 0;
		letters.push_back(k);
		for(int i = 0; i < 26; i++){
			if(f[i] == maior)
				letters.push_back(i);
		}
		sort(letters.begin(), letters.end());
		for(int i = 0; i < letters.size(); i++){	
			resposta = char(letters[i]+97);
			cout << resposta;
		}
		cout << endl;
		letters.clear();
		str.clear();
		maior = 0;
	}
	
	return 0;
}
