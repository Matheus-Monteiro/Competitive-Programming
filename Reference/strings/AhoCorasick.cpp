#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
 
int p[MAX], f[MAX], nxt[MAX][26], ch[MAX];
int tsz = 1; // size of the trie
 
int cnt[MAX]; // used to know number of matches
 
const int S = 2e3+5;
bitset<MAX> elem[S]; // S é tamanho da maior das N strings que são pradõres para buscar no texto
 
void init()
{
    tsz = 1;
    memset(f, 0, sizeof(f));
    memset(nxt, 0, sizeof(nxt));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < MAX; i++) elem[i].reset();
}
 
void add(const string &s, int x)
{
    int cur = 1; // the first element of the trie is the root
    for(int i = 0; s[i]; ++i)
    {
        int j = s[i] - 'a';
        if(!nxt[cur][j])
        {
            tsz++;
            p[tsz] = cur;
            ch[tsz] = j;
            nxt[cur][j] = tsz;
        }
        cur = nxt[cur][j];
    }
    cnt[cur]++;
    elem[cur].set(x);
}
 
void build()
{
    queue<int> q;
    for(int i = 0; i < 26; ++i)
    {
        nxt[0][i] = 1;
        if(nxt[1][i])
            q.push(nxt[1][i]);
    }
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        int u = f[p[v]];
        while(u and !nxt[u][ch[v]]) u = f[u];
        f[v] = nxt[u][ch[v]];
        cnt[v] += cnt[f[v]];
        for(int i = 0; i < 26; ++i)
            if(nxt[v][i])
                q.push(nxt[v][i]);
    }
}
 
bitset<MAX> match(const string &s)
{
    int ans = 0; // Número de matches
    bitset<MAX> found; // Usado pra saber quais strings matches
    int x = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        int t = s[i] - 'a';
        while(x and !nxt[x][t])
            x = f[x];
        x = nxt[x][t];
        ans += cnt[x];
        found |= elem[x];
    }
    return found;
}
 
int main()
{	
    int n;
    string s;   
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        add(s, i);
    }
    build();
    cin >> s;
    bitset<MAX> ans = match(s);
    for(int i = 0; i < n; i++) 
        cout << ans[i] << '\n';
        // 1 se a i-ésima string lida aparece no texto, 0 cc
 
	return 0;
}