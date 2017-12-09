// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Saco do Papai Noel
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1767

#include <bits/stdc++.h>
using namespace std;

int qtd, pTotal, vTotal;//qtd salva quantos objetos eu peguei, pTotal a soma dos pesos de todos os objetos que peguei, vTotal a soma do valor de todos os objetos que peguei

void knapsack(int n, int *p, int *v, int p_max){
    int T[n+1][p_max+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= p_max; w++){
            if(i == 0 or w == 0)
                T[i][w] = 0;
            else{
                if(p[i-1] <= w)
                    T[i][w] = max(v[i-1]+T[i-1][w-p[i-1]], T[i-1][w]);
                else
                    T[i][w] = T[i-1][w];
            }
        }
    }
    vTotal = T[n][p_max];
    for(int i = n; i > 0; i--){
        if(T[i][p_max] != T[i-1][p_max]){//se eu peguei o i-1 obejto
            qtd++;
            pTotal += p[i-1];
            p_max = p_max - p[i-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t, n;
    int peso[110], val[110];
    
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> val[i] >> peso[i];
        pTotal = qtd = 0;
        knapsack(n, peso, val, 50);
        cout << vTotal << " brinquedos" << '\n';
        cout << "Peso: " << pTotal << " kg"<< '\n';
        cout << "sobra(m) " << n-qtd << " pacote(s)" << '\n';
        cout << '\n';
    }
    
    return 0;
}
