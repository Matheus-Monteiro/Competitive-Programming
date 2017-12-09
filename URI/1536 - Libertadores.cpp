// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Libertadores
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1536

#include <iostream>

using namespace std;

int main(){
	
	
	int n, ti1, ti2, tv1, tv2, gol1, gol2;
	char x;
	
	cin >> n;
	while(n--){
		
		cin >> ti1 >> x >> ti2;
		cin >> tv2 >> x >> tv1;
		
		gol1 = ti1 + tv1;
		gol2 = ti2 + tv2;
		 
		if(gol1 > gol2)
			cout << "Time 1" << endl;
		
		if(gol1 < gol2)
			cout << "Time 2" << endl;
				
		if(gol1 == gol2){
			if(ti2 > tv1)
				cout << "Time 2" << endl;
			if(ti2 < tv1)
				cout << "Time 1" << endl;
			if(ti2 == tv1)
				cout << "Penaltis" << endl;		
		}
	}
return 0;
}
