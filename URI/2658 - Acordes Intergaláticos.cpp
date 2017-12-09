// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Acordes Intergaláticos
// Nível: 7
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2658

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;

int n, q;
int A[MAX], segtree[5*MAX][10], lazy[5*MAX], arr[10], ans[10];

void build(int node, int start, int end)
{
    if(start == end)
        segtree[node][A[start]]++;
    else
    {
        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        for(int i = 0; i < 10; i++)
            segtree[node][i] += segtree[2*node][i] + segtree[2*node+1][i];
    }
}

void update(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node])
    {
        for(int i = 0; i < 10; i++) arr[i] = 0;
        for(int i = 0; i < 10; i++)
            arr[(i+lazy[node])%9] += segtree[node][i];
        for(int i = 0; i < 10; i++)
            segtree[node][i] = arr[i];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        else
            A[start] = (A[start] + lazy[node])%9;
        lazy[node] = 0;
    }
    if(start > r or l > end)
        return;
    if(l <= start and end <= r)
    {
        for(int i = 0; i < 10; i++) arr[i] = 0;
        for(int i = 0; i < 10; i++)
            arr[(i+val)%9] += segtree[node][i];
        for(int i = 0; i < 10; i++)
            segtree[node][i] = arr[i];
        if(start != end)
        {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        if(start == end)
            A[start] = (A[start] + val)%9;
    }
    else
    {
        int mid = (start + end)/2;
        update(2*node, start, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        for(int i = 0; i < 10; i++) arr[i] = 0;
        for(int i = 0; i < 10; i++)
            arr[i] += segtree[2*node][i] + segtree[2*node+1][i];
        for(int i = 0; i < 10; i++)
            segtree[node][i] = arr[i];
    }
}

void query(int node, int start, int end, int l, int r)
{
    if(lazy[node])
    {
        for(int i = 0; i < 10; i++) arr[i] = 0;
        for(int i = 0; i < 10; i++)
            arr[(i+lazy[node])%9] += segtree[node][i];
        for(int i = 0; i < 10; i++)
            segtree[node][i] = arr[i];
        if(start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        else
            A[start] = (A[start] + lazy[node])%9;
        lazy[node] = 0;
    }
    if(start > r or l > end)
        return;
    if(l <= start and end <= r)
    {
        for(int i = 0; i < 10; i++)
            ans[i] += segtree[node][i];
        return;
    }
    int mid = (start + end)/2;
    query(2*node, start, mid, l, r);
    query(2*node+1, mid+1, end, l, r);
}

int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        A[i] = 1;
    int a, b;
    build(1, 0, n-1);
    while(q--)
    {
        scanf("%d %d", &a, &b);
        int val, mx = 0;
        memset(ans, 0, sizeof(ans));
        query(1, 0, n-1, a, b);
        for(int i = 0; i < 10; i++)
            if(ans[i] >= mx)
                val = i, mx = ans[i];
        update(1, 0, n-1, a, b, val);
    } 
    for(int i = 0; i < n; i++)
        query(1, 0, n-1, i, i);
    for(int i = 0; i < n; i++)
        printf("%d\n", A[i]);
    
	return 0;
}
