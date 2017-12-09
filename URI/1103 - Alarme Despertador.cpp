// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Alarme Despertador
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1103

#include <bits/stdc++.h>

using namespace std;

int main(){
 	   
	int h1, m1, h2, m2, t1, t2, r;
	
	while((cin >> h1 >> m1 >> h2 >> m2)){
		if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
			break;
		r = 0;
		t1 = h1*60;
		t2 = h2*60;
	
		if(h1 < h2)
			r = t2 - t1 - m1 + m2;
		
		if(h1 == h2){
			if(m1 <= m2)
				r = m2 - m1;
			if(m1 > m2)
				r = 1440 - (m1-m2);
		}
		if(h1 > h2)
			r = 1380 - t1 + t2 + (60 - (m1 - m2));
				
		cout << r << endl;
	}
	
	return 0;
}
