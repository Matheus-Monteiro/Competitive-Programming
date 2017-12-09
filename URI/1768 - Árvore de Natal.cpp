// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Árvore de Natal
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1768

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>

using namespace std;

void centralizar(int n){
    int aux = (n/2)+1, aux2 = 1, q = n/2;
    string s = "****************************************************************************************************";
    while(aux){
        cout << setw(q+1);
        string r;
        r.assign(s, 0, aux2);
        cout << r;
        cout << endl;
        aux2 += 2;
        aux--;
        q++;
    }
    cout << setw((n/2)+1) << right << "*" << endl;
    cout << setw((n/2)+2) << right << "***" << endl;
    cout << endl;
}

int main (){

    int n;
    while(cin >> n)
        centralizar(n);
	return 0;
}

