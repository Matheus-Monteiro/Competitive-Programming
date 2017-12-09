// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Top N
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1943

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	cout << "Top ";
	if(n == 1)
		cout << 1;
	else
		if(n == 2 or n == 3)
			cout << 3;
		else
			if(n == 4 or n == 5)
				cout << 5;
			else
				if(n > 5 and n <= 10)
					cout << 10;
				else
					if(n > 10 and n <= 25)
						cout << 25;
					else
						if(n > 25 and n <= 50)
							cout << 50;
						else
							if( n > 50 and n <= 100)
								cout << 100;
	cout << '\n';
	return 0;
}
