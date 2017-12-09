// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Esquerda, Volver!
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1437

#include <iostream>

using namespace std;

int main(){
	
	int n;
	string str;
	char v[] = {'N', 'L', 'S', 'O'};
	int z;
	
	while(cin >> n && n != 0){
		cin >> str;
		z = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == 'D'){
				if(z == 3)
					z = -1;
				z += 1;
			}else{
				if(z == 0)
					z = 4;
				z -= 1;
			}
		}
		cout << v[z] << endl;
	}
	
	return 0;
}
