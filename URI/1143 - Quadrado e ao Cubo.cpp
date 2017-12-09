// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Quadrado e ao Cubo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1143

#include <iostream>
 using namespace std;
int main()
{
    int n, r=0;

        cin >> n;

        for(int i=1; i<=n; i++){

            r = i;
            cout << r << " ";
            r = i*i;
            cout << r << " ";
            r = i*i*i;
            cout << r << endl;
        }
    return(0);
}

