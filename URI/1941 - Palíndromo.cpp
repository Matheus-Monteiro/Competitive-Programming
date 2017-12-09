// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Palíndromo
// Nível: 4
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1941

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAX = 2020;

string s;
ii memo[MAX][MAX];
int esp[MAX];

ii operator+(const ii a, const ii b)
{
    return ii(a.first+b.first, a.second+b.second);
}

ii max(ii a, ii b)
{
    if(a.first != b.first)
        return a.first > b.first ? a : b;
    return a.second > b.second ? a : b;
}

ii solve(int l, int r)
{
    if(memo[l][r] != ii(-1, -1))
        return memo[l][r];
    if(l == r) 
        return memo[l][r] = ii(esp[l], 1);
    if(l+1 == r)    
        return memo[l][r] = s[l] == s[r] ? ii(esp[l]+esp[r], 2) : ii(esp[l] || esp[r], 1);
    if(s[l] == s[r])
        return memo[l][r] = max(ii(esp[l]+esp[r], 2) + solve(l+1, r-1), max(solve(l+1, r), solve(l, r-1)));
    return memo[l][r] = max(solve(l+1, r), solve(l, r-1));
}

int main()
{
    cin >> s;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        esp[--x] = 1;
    }
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j < s.size(); j++)
            memo[i][j] = {-1, -1};
    cout << solve(0, s.size()-1).second << '\n';    
    
    return 0;
}
