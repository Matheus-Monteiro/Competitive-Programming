// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Corrida
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2396

#include <iostream>
#include <algorithm>
#define MAXN 200

using namespace std;

struct Corrida{
    int c;
    unsigned long long soma;
};

bool comp(Corrida a, Corrida b){
    return a.soma < b.soma;
}

Corrida carros[MAXN];
int n, m;

int main(){
    int tmp, aux;

    cin >> n >> m;

    tmp = m;
    for(int i = 0; i < n; i++){
        while(tmp--){
            cin >> aux;
            carros[i].soma += aux;
            carros[i].c = i;
        }
        tmp = m;
    }

    sort(carros, carros+n, comp);

    cout << carros[0].c+1 << endl << carros[1].c+1 << endl << carros[2].c+1 << endl;

    return 0;
}
