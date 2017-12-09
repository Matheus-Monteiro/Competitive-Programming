// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Movimentos do Cavalo
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1100

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

queue<iii> q;
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

char a, b, c, d;
int x, y, xx, yy;

int solve()
{
    q.push({0, {x, y}});
    while(true)
    {
        int d = q.front().first+1;
        ii pp = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++)
            if(pp.first+dr[i] < 8 and pp.first+dr[i] >= 0 and pp.second+dc[i] < 8 and pp.second+dc[i] >= 0)
            {
                q.push({d, {pp.first+dr[i], pp.second+dc[i]}});
                if(pp.first+dr[i] == xx and pp.second+dc[i] == yy)
                    return d;
            }
    }
}

int main()
{   
    while(cin >> a >> b >> c >> d)
    {        
        x = a-'a';
        y = b-'0'-1;
        xx = c-'a';
        yy = d-'0'-1;
        cout << "To get from " << a << b << " to " << c << d << " takes " << solve() << " knight moves." << '\n';
        q = queue<iii> ();
    }
    return 0;
}
