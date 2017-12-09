// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Validação de Nota
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1117

#include <iostream>

using namespace std;

int main()
{
    double x=0, y=0, media;

        do{
            cin >> x;
            if(x<0 || x>10)
                cout << "nota invalida" << endl;
        }while(x<0 || x>10);

        do{
            cin >> y;
            if(y<0 || y>10)
                cout << "nota invalida" << endl;
        }while(y<0 || y>10);


            media = (x+y)/2;
            cout.precision(2);
            cout << fixed;
            cout << "media = " << media << endl;

    return 0;
}
