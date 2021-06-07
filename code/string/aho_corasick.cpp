#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
 
int p[MAX], f[MAX], nxt[MAX][26], ch[MAX];
int tsz = 1; // size of the trie
 
int cnt[MAX]; // used to know number of matches
 
const int S = 2e3+5;
bitset<MAX> elem[S]; 
// S eh tamanho da maior das N strings que sao
// pradroes para buscar no texto
 
void init()
{
    tsz = 1;
    memset(f, 0, sizeof(f));
    memset(nxt, 0, sizeof(nxt));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < MAX; i++) 
    	elem[i].reset();
}
 
void add(const string &s, int x)
{
	// the first element of the trie is the root
    int cur = 1; 
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
    int ans = 0; 
    // Numero de matches
    bitset<MAX> found; 
    // Usado pra saber quais strings matches
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
        // 1 se a i-esima string lida
        // aparece no texto, 0 cc
	return 0;
}

//#############################################################################################

#include <bits/stdc++.h>
using namespace std;

const int K = 60;

struct Vertex {
   int next[K];
   bool leaf = false;
   int p = -1;
   char c;
   int link = -1;
   int go[K];
   bitset<1005> S; 
   Vertex(int _p=-1, char _c = '$') : p(_p), c(_c) {
      fill(begin(next), end(next), -1);
      fill(begin(go), end(go), -1);
   }
};

vector<Vertex> t;

void init() {
   t.clear();
   t.resize(1);
}

void add(string &s, int i) {
   int v = 0;
   for(char ch : s) {
      int c = ch - 'A';
      if(t[v].next[c] == -1) {
         t[v].next[c] =  t.size();
         t.push_back(Vertex(v, ch));
      }
      v = t[v].next[c];
   }
   t[v].leaf = true;
   t[v].S[i] = 1;
}

int go(int v, char ch);

int get_link(int v) {
   if(t[v].link == -1) {
      if(v == 0 or t[v].p == 0)
         t[v].link = 0;
      else
         t[v].link = go(get_link(t[v].p), t[v].c);
   }
   return t[v].link;
}

int go(int v, char ch) {
   int c = ch - 'A';
   if(t[v].go[c] == -1) {
      if(t[v].next[c] != -1)
         t[v].go[c] = t[v].next[c];
      else 
         t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
   }
   return t[v].go[c];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
   
   int caso;
   cin >> caso;
   while(caso--) {
      init();
      string s;
      int n;
      cin >> s >> n;
      bitset<1005> S;
      for(int i = 0; i < n; i++) {
         string a;
         cin >> a;
         add(a, i);
      }
      int v = 0;
      for(char &c : s) {
         v = go(v, c);
         S |= t[v].S;
      }
      for(int i = 0; i < n; i++)
         cout << (S[i] ? 'y' : 'n') << '\n';
   }

	return 0;
}
