// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Aumento de Salário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1048

#include <iostream>

using namespace std;

int main (){

  double s, r;
  
  cin >> s;
  
  if(s > 0.00 && s <= 400.00)
    {   
        r = 0.15*s;
        s = 1.15*s;
        cout.precision(2);
        cout << fixed ;
        cout << "Novo salario: " << s << "\n";
        cout << "Reajuste ganho: " << r << "\n";
        cout << "Em percentual: 15 \%\n";
        s = s-r;
    }
    
  if(s >= 400.01 && s <= 800.00)
    {
        r = 0.12*s;
        s = 1.12*s;
        cout.precision(2);
        cout << fixed ;
        cout << "Novo salario: " << s << "\n";
        cout << "Reajuste ganho: " << r << "\n";
        cout << "Em percentual: 12 \%\n";
        s = s-r;
    }
    
  if(s >= 800.01 && s <= 1200)
    {
        r = 0.10*s;
        s = 1.10*s;
        cout.precision(2);
        cout << fixed ;
        cout << "Novo salario: " << s << "\n";
        cout << "Reajuste ganho: " << r << "\n";
        cout << "Em percentual: 10 \%\n";
        s = s-r;
    }
    
  if(s >= 1200.01 && s <= 2000)
    {
        r = 0.07*s;
        s = 1.07*s;
        cout.precision(2);
        cout << fixed ;
        cout << "Novo salario: " << s << "\n";
        cout << "Reajuste ganho: " << r << "\n";
        cout << "Em percentual: 7 \%\n";
        s = s-r;
    }

  if(s > 2000)
    {
        r = 0.04*s;
        s = 1.04*s;
        cout.precision(2);
        cout << fixed ;
        cout << "Novo salario: " << s << "\n";
        cout << "Reajuste ganho: " << r << "\n";
        cout << "Em percentual: 4 \%\n";
        s = s-r;
    }
}

