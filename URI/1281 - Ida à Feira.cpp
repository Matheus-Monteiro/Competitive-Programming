// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ida à Feira
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1281

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, double> mapa;
    string fruta;
    double valor, total;
    int n, m, q, p;
    
    cin >> n;
    
    while(n--){
        cin >> m;
        cin.ignore();
        while(m--){
            cin >> fruta >> valor;
            mapa[fruta] = valor;
        }
        cin >> p;
        cin.ignore();
        total = 0.0;
        while(p--){
            cin >> fruta >> q;
            total += (double)q*mapa[fruta];
        }
        cout.precision(2);
        cout << fixed;
        cout << "R$ " << total << '\n';
        mapa.clear();
    }
    
    
    return 0;
}
