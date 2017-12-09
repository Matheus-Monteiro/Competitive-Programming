// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fase
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2663

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;   
    vector<int> v;

    cin >> n >> k;
    v.resize(n);
    for(int &p : v)
        cin >> p;
    sort(v.begin(), v.end(), [](int a, int b){return a > b;});
    int cont = 1, ant = v[0];
    for(int i = 1; i < n; i++)
        if(i < k)
            cont++, ant = v[i];
        else 
        {
            while(ant == v[i++])
                cont++;
            i = n;  
        }
    cout << cont << '\n';
    
    return 0;
}
