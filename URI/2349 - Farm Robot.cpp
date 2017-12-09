// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Farm Robot
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2349

#include <iostream>
#define MAXN 1010

using namespace std;

int v[MAXN];
int n, c, e, cont;

int main(){
	cin >> n >> c >> e;

	for(int i = 1; i <= c; i++)
		cin >> v[i];
	
	if(e == 1)
		cont = 1;
	else
		cont = 0;
	
	int x = 1;
	for(int i = 1; i <= c; i++){
			if(v[i] == 1 and x < n)
				x++;
			else
				if(v[i] == 1 and x == n)
					x = 1;
				else
					if(v[i] == -1 and x > 1)
						x--;
					else
						if(v[i] == -1 and x == 1)
							x = n;	
			if(x == e)
				cont++;
	
	}
	cout << cont << endl;

	return 0;
}
