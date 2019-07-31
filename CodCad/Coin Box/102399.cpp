#include <bits/stdc++.h>

using namespace std;
int A[400000], st[400000], lazy[400000], n, q, k, a ,b, o;

/*void build(int pos, int i , int j, int valor)
{
    int esquerda = pos << 1, direita = (pos << 1) + 1, mid = (i + j)>>1;
    if(i == j)
    {    
        st[pos] = valor;
        return;
    }
    if(i > n or j < 0)
        return;
    build(esquerda, i, mid,valor);
    build(direita, mid +1, j, valor);
    st[pos] = st[esquerda] + st[direita];
}*/

void build(int node, int start, int end)
{
    if(start == end)
        st[node] = A[start];
    else
    {
        int mid = (start + end) >> 1;
        build((node << 1), start, mid);
        build((node << 1) + 1, mid + 1, end);
        st[node] = st[node << 1] + st[(node << 1) + 1];
    }
}

void update(int pos, int i, int j, int a, int b, int valor)
{
    
    int esquerda = pos << 1, direita = (pos << 1) + 1, mid = (i + j)>>1;
    if(lazy[pos])
    {
        st[pos] = lazy[pos]*(j- i +1);
        if(i!=j)
            lazy[esquerda] = lazy[pos], lazy[direita]=lazy[pos];
        lazy[pos] = 0;    
    
    } 
    if(i > b || j < a ) return;
    if(i >= a && j <= b)
    {
        st[pos] = valor*(j-i+1);
        if(i!=j)
            lazy[esquerda] = valor, lazy[direita]=valor;
    }
    else
    {
      update(esquerda, i, mid, a , b, valor);
      update(direita, mid +1, j, a, b, valor);
      st[pos] = st[esquerda] + st[direita];    
    }
}

int query(int pos, int i, int j, int a, int b)
{
    int esquerda = pos << 1, direita = (pos << 1) + 1, mid = (i + j)>>1;
    if(lazy[pos])
    {
        st[pos] = lazy[pos]*(j- i +1);
        if(i!=j)
            lazy[esquerda] = lazy[pos], lazy[direita]=lazy[pos];
        lazy[pos] = 0;    
    
    } 
    if(i > b || j < a ) return 0;
    if(i >= a && j <= b)
        return st[pos];
    else
    {
        int p1 = query(esquerda, i, mid, a, b),
        p2 = query(direita, mid +1, j, a, b);
        return p1 + p2;     
    }    
}
int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {int x; cin >> A[i]; }
    build(1, 1, n);
    while(q--)
    {
        cin >> o >> a >> b;
        if(o == 1)
        {
            cin >> k;
            update(1, 1, n, a, b, k);
        }
        else
            cout << query(1, 1, n, a, b) <<'\n';
   }   
}