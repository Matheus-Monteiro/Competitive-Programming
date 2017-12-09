// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Frequência de Números
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1171

#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v, aux;
    int n, num;
    
    cin >> n;
    aux.resize(2005);
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
        aux[num]++;
    }
    
    for(int i = 0; i < 2004; i++)
        if(aux[i] != 0)
            cout << i << " aparece " << aux[i] << " vez(es)" << "\n";

    return 0;
}
