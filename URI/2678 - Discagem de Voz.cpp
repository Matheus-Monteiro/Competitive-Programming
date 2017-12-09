// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Discagem de Voz
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2678

#include <bits/stdc++.h>
using namespace std;

const int OO = 0x3f3f3f3f;
const int MAX = 1e5;
const double EPS = 1e-8;

#define bug(x) cout << #x << ' ' << x <<< '\n';
#define FOR(i, a, n) for(int i = 0; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
    map<char, int> mp;
    mp['A'] = 2;
    mp['B'] = 2;
    mp['C'] = 2;
    mp['D'] = 3;
    mp['E'] = 3;
    mp['F'] = 3;
    mp['G'] = 4;
    mp['H'] = 4;
    mp['I'] = 4;
    mp['J'] = 5;
    mp['K'] = 5;
    mp['L'] = 5;
    mp['M'] = 6;
    mp['N'] = 6;
    mp['O'] = 6;
    mp['P'] = 7;
    mp['Q'] = 7;
    mp['R'] = 7;
    mp['S'] = 7;
    mp['T'] = 8;
    mp['U'] = 8;
    mp['V'] = 8;
    mp['W'] = 9;
    mp['X'] = 9;
    mp['Y'] = 9;
    mp['Z'] = 9;

    string str;
    
    while(getline(cin, str))
    {
        for(const auto &c : str)
            if(c != '-')
            {
                if(isdigit(c) or c == '#' or c == '*')
                    cout << c;
                else if(isalpha(c))
                    cout << mp[toupper(c)];
            }
        cout << '\n';
    }
    

    return 0;
}
