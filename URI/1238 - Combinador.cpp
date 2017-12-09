// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Combinador
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1238

#include <iostream>
#include <string.h>

using namespace std;

int main(){

	char str1[55], str2[55], str[110];
	int n, aux1, aux2;
	
	cin >> n;
	
	while(n--){
		cin >> str1 >> str2;
		
		int tam1 = strlen(str1);
		int tam2 = strlen(str2);
		
		(tam1 > tam2) ? aux1 = tam2 : aux1 = tam1;
		
		int j = 0;
		for(int i = 0; i < aux1; i++){
			str[j] = str1[i];
			j++;
			str[j] = str2[i];
			j++;
		}
		
		(tam1 > tam2) ? aux2 = tam1 : aux2 = tam2;
		
		for(int i = aux1; i < aux2; i++){
			if(tam1 > tam2)
				str[j] = str1[i];
			if(tam1 < tam2)
				str[j] = str2[i];
			j++;
		}
		
		str[j] = '\0';
		
		cout << str << endl;
	}

	return 0;
}
