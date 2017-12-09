// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Quadrante
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1115

#include <iostream>

using namespace std;

int main()
{
    int x=1, y=1;

        while(x != 0 && y != 0){
            cin >> x >> y;

            if(x == 0 && y == 0)
                return 0;

            if(x>0 && y>0)
                cout << "primeiro" << endl;

            if(x<0 && y<0)
                cout << "terceiro" << endl;

            if(x>0 && y<0)
                cout << "quarto" << endl;

            if(x<0 && y>0)
                cout << "segundo" << endl;
        }

    return 0;
}

