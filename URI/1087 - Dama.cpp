// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dama
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1087

#include <iostream>

using namespace std;

int main(){

	int x1, y1, x2, y2;
	
	while((cin >> x1 >> y1 >> x2 >> y2) ,x1,y1,x2,y2){
		if(x1 == x2 && y1 == y2)
			cout << "0" << endl;
		else
			if((x1 + y1 == x2 + y2) || (x1 - y1 == x2 - y2) || (x1 == x2) || (y1 == y2))
				cout << "1" << endl;
			else
				cout << "2" << endl;
	}

return 0;
}
