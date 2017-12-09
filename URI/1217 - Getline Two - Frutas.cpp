// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Getline Two - Frutas
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1217

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, d, aux, qtd_total = 0, caso = 1;
    double preco, preco_total = 0.0;
     string str;
    
    cin >> n;
    d = n;
    while(n--){
        cin >> preco;
        cin.ignore();
        getline(cin, str);
        aux = 1;
        for(int i = 0; i < str.size(); i++)
            if(str[i] == ' ')
                aux++;
        qtd_total += aux;
        preco_total += preco;
        cout << "day " << caso << ": " << aux << " kg" << endl;
        caso++;
    }
    cout.precision(2);
    cout << fixed;
    cout << (double)qtd_total/d << " kg by day" << endl;
    cout << "R$ " << (double)preco_total/d << " by day" << endl;

    return 0;
}
