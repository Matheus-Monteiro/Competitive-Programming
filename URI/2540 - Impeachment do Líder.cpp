// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Impeachment do Líder
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2540

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5; 
const int OO = 0x3f3f3f3f;

#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
    int n, v;
    
    while(~scanf("%d", &n))
    {
        int qtd = 0;
        REP(i, n)
        {
            scanf("%d", &v);
            qtd += v;
        }
        printf(3*qtd >= 2*n ? "impeachment\n" : "acusacao arquivada\n");    
    }    

        
    return 0;
}
