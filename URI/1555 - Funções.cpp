// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Funções
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1555

#include <bits/stdc++.h>

using namespace std;




int main(){
    
	int b, c, r, n;
    
	int x, y;
     
	cin >> n;
    
    
	while(n--){
      
		cin >> x >> y;
      
		r = 9*x*x + y*y;

    		b = 2*x*x + 25*y*y;
		c = (-1)*100*x + y*y*y;
		if(r > b and r > c)
			cout << "Rafael ganhou" << '\n';
		else if(b > r and b > c)
			cout << "Beto ganhou" << '\n';
		else
			cout << "Carlos ganhou" << '\n';
	}
  
    

	return 0;

}
