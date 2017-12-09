// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Homem, Elefante e Rato
// Nível: 8
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1477

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int segtree[MAX][3], lazy[MAX], ans[3], arr[3], n, q;

void build(int node, int start, int end)
{
    if(start == end)
        segtree[node][0]++;
    else
    {
        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        for(int i = 0; i < 3; i++)
            segtree[node][i] = segtree[2*node][i] + segtree[2*node+1][i];
    }
}

void update(int node, int start, int end, int l, int r)
{
    if(lazy[node])
    {
        for(int i = 0; i < 3; i++)
            arr[(i+lazy[node])%3] = segtree[node][i]; 
        for(int i = 0; i < 3; i++)
            segtree[node][i] = arr[i];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end or r < start)
        return;
    if(l <= start and end <= r)
    {
        for(int i = 0; i < 3; i++)
            arr[(i+1)%3] = segtree[node][i]; 
        for(int i = 0; i < 3; i++)
            segtree[node][i] = arr[i];
        lazy[2*node]++;
        lazy[2*node+1]++;
    }
    else
    {
        int mid = (start+end)/2;
        update(2*node, start, mid, l, r);
        update(2*node+1, mid+1, end, l, r);
        for(int i = 0; i < 3; i++)
            segtree[node][i] = segtree[2*node][i] + segtree[2*node+1][i];
    }
}

void query(int node, int start, int end, int l, int r)
{
    if(lazy[node])
    {
        for(int i = 0; i < 3; i++)
            arr[(i+lazy[node])%3] = segtree[node][i];
        for(int i = 0; i < 3; i++)
            segtree[node][i] = arr[i];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(r < start or l > end)
        return;
    if(l <= start and end  <= r)
    {
        for(int i = 0; i < 3; i++)
            ans[i] += segtree[node][i];
        return;
    }
    int mid = (start+end)/2;
    query(2*node, start, mid, l, r);
    query(2*node+1, mid+1, end, l, r);
}

int main()
{
    int x, y;
    char c;

    while(cin >> n >> q)
    {
        memset(lazy, 0, sizeof(lazy));
        memset(segtree, 0, sizeof(segtree));
        build(1, 0, n-1);
        while(q--)
        {
            cin >> c >> x >> y;
            if(c == 'M')
                update(1, 0, n-1, x-1, y-1);
            else
            {
                ans[0] = ans[1] = ans[2] = 0;
                query(1, 0, n-1, x-1, y-1);
                cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
