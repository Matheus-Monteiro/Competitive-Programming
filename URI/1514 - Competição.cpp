// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Competição
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1514

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, ans;
int matriz[105][105];

int main()
{
    while(cin >> n >> m and (n or m))
    {
        ans = 4;
        REP(i, n)   
            REP(j, m)
                cin >> matriz[i][j];
        REP(i, n)
        {
            int cont = 0;
            REP(j, m)
                cont += matriz[i][j];
            if(cont == m)
            {
                ans--;
                break;
            }
        }
        
        REP(j, m)
        {
            int cont = 0;
            REP(i, n)
                cont += matriz[i][j];
            if(!cont)
            {
                ans--;
                break;
            }
        }
     
        REP(j, m)
        {
            int cont = 0;
            REP(i, n)
                cont += matriz[i][j];
            if(cont == n)
            {
                ans--;
                break;
            }
        }
     
        REP(i, n)
        {
            int cont = 0;
            REP(j, m)
                cont += matriz[i][j];
            if(!cont)
            {
                ans--;
                break;
            }
        }
        cout << ans << '\n';
    }
	return 0;
}
