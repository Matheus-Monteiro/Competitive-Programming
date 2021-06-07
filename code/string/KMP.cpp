#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int n, m; 
// n eh o tamanho do texto e m eh o
// tamanho do padrao
int arr[MAX]; 
// array que guarda o tamanho do maior 
// prefixo proprio que tambem eh sufixo
string t, p; // t eh o texto e p eh o padrao

void build() // kMP Preprocess
{
    int i = 0, j = 1;
    while(j < m)
    {
        if(p[i] == p[j])
            arr[j] = ++i;
        else
        {
            i = 0;
            if(p[i] == p[j])
                arr[j] = ++i;
        }
        j++;
    }
}

int matching() // KMP search
{
    int i = 0, j = 0;
    while(j < n)
    {
        if(p[i] == t[j]) i++, j++;
        else if(i) i = arr[i - 1];
        else j++;
        if(i == m)
            return j - m;
    // a substring P inicia na posicao j - m em T
    }
    return -1; // P nao eh substring de T
}

int main()
{
    cin >> t >> p;
    n = (int)t.size();
    m = (int)p.size();
    build();
    cout << matching() << '\n';
    
    return 0;
}
