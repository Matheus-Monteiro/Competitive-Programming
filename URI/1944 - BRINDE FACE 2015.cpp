// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: BRINDE FACE 2015
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1944

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
//#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

stack<char> s; 

void face()
{
    s.push('F');
    s.push('A');
    s.push('C');
    s.push('E');
}

bool check(string str)
{
    string aux;
    REP(i, 4) aux += s.top(), s.pop();
    if(aux == str) return true;
    for(int i = 3; i >= 0; i--)
        s.push(aux[i]);
    REP(i, 4) s.push(str[i]);
    return false;
}

int main()
{
    string str;      
    char c;
    int n;
    
    cin >> n;
    int ans = 0;

    while(n--)
    {
        str = "";
        REP(i, 4) cin >> c, str.pb(c);
        if(s.empty()) face();
        if(check(str))
            ans++;
    }
    cout << ans << '\n';   

	return 0;
}
