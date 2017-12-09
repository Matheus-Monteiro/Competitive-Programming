// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Six Flags
// Nível: 2
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1487

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Brinquedo{
	int D, P;
	double div;	
};
	
bool comp(Brinquedo a, Brinquedo b){
	return a.div > b.div;
}
	
int main(){
	int n, t, h = 1;
	
	Brinquedo brinquedos[1000];
	
	while(cin >> n >> t && n != 0 || t != 0){
		for(int i = 0; i < n; i++){
			cin >> brinquedos[i].D >> brinquedos[i].P;
			brinquedos[i].div = (double)brinquedos[i].P/brinquedos[i].D;
		}
		sort(brinquedos, brinquedos+n, comp);
		
		int cont = 0, tempo = 0, i = 0;
		while(i < n){
			if(tempo+brinquedos[i].D <= t){
				cont += brinquedos[i].P;
				tempo += brinquedos[i].D;
			}else
			{
				i++;
			}
		}
		cout << "Instancia " << h++ << endl << cont << endl << endl;
	}
	
	return 0;
}
