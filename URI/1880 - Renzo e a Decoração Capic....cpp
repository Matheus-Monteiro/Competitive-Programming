// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Renzo e a Decoração Capic...
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1880

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 
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

bool solve(int n, int b)
{
    string str;
    while(n)
    {
        int c = n%b;
        n /= b;
        str.push_back(char(c-'0'));
    }
    string aux = str;
    reverse(aux.begin(), aux.end());
    return aux == str;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        bool ok = true, fl = false;
        for(int i = 2; i <= 16; i++)
            if(solve(n, i))
            {
                if(fl) cout << ' ';
                else fl = true;
                cout << i;
                ok = false;
            }
        if(ok) cout << -1;
        cout << '\n';
    }
    
	return 0;
}
