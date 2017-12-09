// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Voleibol
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2310

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string nome;
	double q, w, e;
	double s = 0.0, b = 0.0, c = 0.0;
	double ss = 0.0, bb = 0.0, cc = 0.0;
	int n;
	
	cin >> n;
	while(n--)
	{
		cin >> nome >> q >> w >> e;
		s += q; b += w; c += e;
		cin >> q >> w >> e;
		ss += q; bb += w; cc += e;
	}
	cout << fixed << setprecision(2);
	cout << "Pontos de Saque: " << (ss/s)*100 << " %.\n"; 
	cout << "Pontos de Bloqueio: " << (bb/b)*100 << " %.\n"; 
	cout << "Pontos de Ataque: " << (cc/c)*100 << " %.\n"; 

	return 0;
}
