// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Qual Triângulo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2313

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int v[3];
	
	cin >> v[0] >> v[1] >> v[2];
	
	sort(v, v+3);
	
	if(v[0] + v[1] > v[2]){
		if(v[0] == v[1] and v[0] == v[2])
			cout << "Valido-Equilatero" << endl;
		else
			if(v[0] == v[1] or v[0] == v[2] or v[1] == v[2])
				cout << "Valido-Isoceles" << endl;
			else
				cout << "Valido-Escaleno" << endl;		
		(v[2]*v[2] == v[0]*v[0] + v[1]*v[1]) ? cout << "Retangulo: S" << endl : cout << "Retangulo: N" << endl;
			
	}else{
		cout << "Invalido" << endl;
	}
	
	return 0;
}
