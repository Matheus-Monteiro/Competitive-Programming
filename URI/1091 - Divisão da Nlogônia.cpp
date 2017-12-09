// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Divisão da Nlogônia
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1091

#include <iostream>

using namespace std;

int main (){

    int m, n, x, y, k, d;
    while(cin >> k && k!=0){
        cin >> m >> n;
        for(int i=0;i<k;i++){
            cin >> x >> y;
            if(x == m || y == n)
                cout << "divisa" << endl;
            if(x > m && y > n)
                cout << "NE" << endl;
            if(x < m && y > n)
                cout << "NO" << endl;
            if(x < m && y < n)
                cout << "SO" << endl;
            if(x > m && y < n)
                cout << "SE" << endl;
        }
     }
     return 0;
}

