https://codeforces.com/blog/entry/44351

// Small To Large (using map)
// Given a tree, every vertex has color. Query is 
//how many vertices in subtree of vertex v are 
// colored with color c?
// O(N*logN*logN), (we are using map)

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10; 

vector<int> g[MAX];
int sz[MAX], col[MAX];
map<int, int> *cnt[MAX];

void getsz(int v, int p)
{
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v); sz[v] += sz[u]; } }

void dfs(int v, int p)
{
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p)
       {
           dfs(u, v);
           if(sz[u] > mx)
               mx = sz[u], bigChild = u;
       }
    if(bigChild != -1)
        cnt[v] = cnt[bigChild];
    else
        cnt[v] = new map<int, int> ();
    (*cnt[v])[ col[v] ] ++;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           for(auto x : *cnt[u])
               (*cnt[v])[x.first] += x.second;
    //now (*cnt[v])[c] is the number of vertices in 
    //subtree of vertex v that has color c. You can 
    //answer the queries easily.
}

int32_t main()
{
    int n, m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> col[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getsz(0, -1);
    dfs(0, -1);
            
	return 0;
}


/////////////////////////////////////////////////////


// dsu on tree (using vector)
// Given a tree, every vertex has color. Query is 
//how many vertices in subtree of vertex v are 
// colored with color c?
// O(N*logN)

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10; 

vector<int> g[MAX];
int sz[MAX], col[MAX];
vector<int> *vec[MAX];
int cnt[MAX];

void getsz(int v, int p)
{
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v); sz[v] += sz[u]; } }


void dfs(int v, int p, bool keep)
{
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
           mx = sz[u], bigChild = u;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           dfs(u, v, 0);
    if(bigChild != -1)
        dfs(bigChild, v, 1), vec[v] = vec[bigChild];
    else
        vec[v] = new vector<int> ();
    vec[v]->push_back(v);
    cnt[ col[v] ]++;
    for(auto u : g[v])
       if(u != p && u != bigChild)
           for(auto x : *vec[u]){
               cnt[ col[x] ]++;
               vec[v] -> push_back(x);
           }
//now (*cnt[v])[c] is the number of vertices in subtree
//of vertex v that has color c. You can answer the queries 
//easily. note that in this step *vec[v] contains all of 
//the subtree of vertex v.
    if(keep == 0)
        for(auto u : *vec[v])
            cnt[ col[u] ]--;
}

int32_t main()
{
    int n, m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> col[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getsz(0, -1);
    dfs(0, -1, 0);
            
	return 0;
}

// Small To Large (heavy-light decomposition style)
// Given a tree, every vertex has color. Query is 
//how many vertices in subtree of vertex v are 
// colored with color c?
// O(N*logN)

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10; 

vector<int> g[MAX];
int sz[MAX], col[MAX];
bool big[MAX];
int cnt[MAX];

void getsz(int v, int p)
{
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v); sz[v] += sz[u]; } }

void add(int v, int p, int x)
{
    cnt[ col[v] ] += x;
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}

void dfs(int v, int p, bool keep)
{
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
        // run a dfs on small childs and clear them from cnt
            dfs(u, v, 0);  
    if(bigChild != -1)
        // bigChild marked as big and not cleared from cnt
        dfs(bigChild, v, 1), big[bigChild] = 1;
    add(v, p, 1);
//now cnt[c] is the number of vertices in subtree of 
//vertex v that has color c. You can answer the queries easily.
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}

int32_t main()
{
    int n, m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> col[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getsz(0, -1);
    dfs(0, -1, 0);
            
	return 0;
}

// Small To Large (using nesting intervals)
// Given a tree, every vertex has color. Query is 
//how many vertices in subtree of vertex v are 
// colored with color c?
// O(N*logN)

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10; 

vector<int> g[MAX];
int sz[MAX], col[MAX];
int st[MAX], ft[MAX];
int cnt[MAX], ver[MAX];
int tempo = 0;

void getsz(int v, int p)
{
    sz[v] = 1;
    ver[tempo] = v;
    st[v] = tempo++;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v); sz[v] += sz[u]; } 
    ft[v] = tempo++;            
}

void dfs(int v, int p, bool keep)
{
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
        if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            // run a dfs on small childs and 
            // clear them from cnt
            dfs(u, v, 0);  
    if(bigChild != -1)
        // bigChild marked as big and not cleared from cnt
        dfs(bigChild, v, 1); 
    for(auto u : g[v])
	if(u != p && u != bigChild)
	    for(int p = st[u]; p < ft[u]; p++)
		    cnt[ col[ ver[p] ] ]++;
    cnt[ col[v] ]++;
//now cnt[c] is the number of vertices in subtree of vertex
//v that has color c. You can answer the queries easily.
    if(v == 1) cout << cnt[2] << '\n';
    if(keep == 0)
        for(int p = st[v]; p < ft[v]; p++)
	        cnt[ col[ ver[p] ] ]--;
}

int32_t main()
{
    int n, m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> col[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getsz(0, -1);
    dfs(0, -1, 0);
            
	return 0;
}

/*
But why it is ? You know that why dsu has time 
(for q queries); the code uses the same method.
Merge smaller to greater.

If you have heard heavy-light decomposition you
will see that function add will go light edges
only, because of this, code works in time.

*/
