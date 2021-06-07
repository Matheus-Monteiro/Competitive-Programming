//com hash no braco

#include <bits/stdc++.h>
using namespace std;
const int MAX = 3 * 1e5;

struct Query
{
    int l, r, qt;
    vector<int> el;
};

Query q[MAX];
int n, m, blk, ans;
int arr[MAX], freq[MAX], qtd[MAX], pos[MAX];
vector<vector<int>> tab;

void add(int i)
{
    if(freq[arr[i]])
        qtd[freq[arr[i]]]--;
    freq[arr[i]]++;
    qtd[freq[arr[i]]]++;
    if(ans <= freq[arr[i]])
    {
        ans = freq[arr[i]];   
        tab[ans].push_back(arr[i]);
    }
}

void sub(int i)
{
    qtd[freq[arr[i]]]--;
    if(!qtd[ans])
    {
        for(int j = 0; j < tab[ans].size(); j++)
            if(tab[ans][j] == arr[i])
            {
                tab[ans].erase(tab[ans].begin() + j);
                break;
            }
        ans--;
        tab[ans].push_back(arr[i]);
    }
    freq[arr[i]]--;
    if(freq[arr[i]])
        qtd[freq[arr[i]]]++;
}

bool compare(int a, int b)
{
    if(q[a].l/blk != q[b].l/blk)
        return q[a].l < q[b].l;
    return q[a].r < q[b].r;
}

int main()
{
    while(cin >> n >> m and n)
    {
        blk = sqrt(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] += 100000;
        }
        for(int i = 0; i < m; i++)
            cin >> q[i].l >> q[i].r, pos[i] = i;
        
        sort(pos, pos + m, compare);
        
        ans = 0;
        int curL = 0, curR = 0;       
        int L, R;
        
        memset(freq, 0, sizeof(freq));
        memset(qtd, 0, sizeof(qtd));
        tab.clear();
        tab.resize(MAX);
        
        for(int j = 0; j < m; j++)
        {   
            L = q[pos[j]].l - 1;
            R = q[pos[j]].r - 1;
            while(curL < L)
                sub(curL++);
            while(curL > L)
                add(--curL);
            while(curR < R + 1)    
                add(curR++);
            while(curR > R + 1)
                sub(--curR);
            q[pos[j]].qt = ans; 
            q[pos[j]].el = tab[ans];
        }
        for(int j = 0; j < m; j++)
            for(int i = 0; i < q[j].el.size(); i++)
                cout << q[j].el[i]-100000 << '\n';
    }   
       
    return 0;
}

////////////////////////////////////////////////
//com unordered_multimap

#include <bits/stdc++.h>
using namespace std;
const int MAX = 3 * 1e5;

struct Query
{
    int l, r, qt, morefrequent;
};

Query q[MAX];
int n, m, blk, ans;
int arr[MAX], freq[MAX], qtd[MAX], pos[MAX];
unordered_multimap<int, int> tab;

void add(int i)
{
    if(freq[arr[i]])
        qtd[freq[arr[i]]]--;
    freq[arr[i]]++;
    qtd[freq[arr[i]]]++;
    if(ans <= freq[arr[i]])
    {
        ans = freq[arr[i]];   
        tab.insert({ans, arr[i]});
    }
}

void sub(int i)
{
    qtd[freq[arr[i]]]--;
    if(!qtd[ans])
    {
        int k = 0, sz = tab.bucket(ans);
        auto it = tab.find(ans);
        for(int j = 0; j < sz; j++)
            if(it->second == arr[i])
            {
                tab.erase(it);
                j = sz;
            }
            else it++;
                
        ans--;
        tab.insert({ans, arr[i]});
    }
    freq[arr[i]]--;
    if(freq[arr[i]])
        qtd[freq[arr[i]]]++;
}

bool compare(int a, int b)
{
    if(q[a].l/blk != q[b].l/blk)
        return q[a].l < q[b].l;
    return q[a].r < q[b].r;
}

int main()
{
    while(cin >> n >> m and n)
    {
        blk = sqrt(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] += 100000;
        }
        for(int i = 0; i < m; i++)
            cin >> q[i].l >> q[i].r, pos[i] = i;
        
        sort(pos, pos + m, compare);
        
        ans = 0;
        int curL = 0, curR = 0;       
        int L, R;
        
        memset(freq, 0, sizeof(freq));
        memset(qtd, 0, sizeof(qtd));
        tab.clear();
        
        for(int j = 0; j < m; j++)
        {   
            L = q[pos[j]].l - 1;
            R = q[pos[j]].r - 1;
            while(curL < L)
                sub(curL++);
            while(curL > L)
                add(--curL);
            while(curR < R + 1)    
                add(curR++);
            while(curR > R + 1)
                sub(--curR);
            q[pos[j]].qt = ans; 
            q[pos[j]].morefrequent = tab.find(ans)->second;
        }
        for(int j = 0; j < m; j++)
                cout << q[j].morefrequent-100000 << '\n';
    }   
       
    return 0;
}

/////////////////////////////////////////
Mo em arvore parte 1

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;

struct Query
{
    int l, r, v;
};

int n, q;
int freq[MAX], inicio[MAX], fim[MAX], pos[MAX], value[MAX];
vector<int> tree_linearization, G[MAX];
Query Q[MAX];
int ans, blk;

void TreeLinearization(int v, int p)
{
    inicio[v] = tree_linearization.size();
    tree_linearization.push_back(v);
    for(const int &u : G[v])
        if(u != p)
            TreeLinearization(u, v);
    fim[v] = tree_linearization.size() - 1;
}

void add(int i)
{
    if(!freq[value[tree_linearization[i]]])
        ans++;
    freq[value[tree_linearization[i]]]++;
}

void sub(int i)
{
    freq[value[tree_linearization[i]]]--;
    if(!freq[value[tree_linearization[i]]])
        ans--;
}

bool compare(int a, int b)
{
    if(Q[a].l/blk != Q[b].l/blk)
        return Q[a].l/blk < Q[b].l/blk;
    return Q[a].r < Q[b].r;
}

int main()
{
    int u, v;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> value[i];
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    TreeLinearization(0, -1);
    for(int i = 0; i < q; i++)
    {
        cin >> u;
        u--; 
        Q[i].l = inicio[u];
        Q[i].r = fim[u];
        pos[i] = i;
    }
    blk = sqrt(n);
    sort(pos, pos+q, compare);
    int curL = 0, curR = 0;   
    for(int i = 0; i < q; i++)
    {
        int L = Q[pos[i]].l, R = Q[pos[i]].r;
        while(curL < L) 
            sub(curL++);
        while(curL > L)
            add(--curL);       
        while(curR < R + 1)
            add(curR++);
        while(curR > R + 1)
            sub(--curR);
        Q[pos[i]].v = ans;
    }
    for(int i = 0; i < q; i++)
        cout << Q[i].v << '\n';
    
    return 0;
}
