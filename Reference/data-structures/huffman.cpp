#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
typedef pair<int, int> ii;

string s; // letras de 'a' para 'z' (minusculas)
int n, cnt[26], node;
vector<int> tree[MAX];
map<char, string> encript;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dfs(int u, string bitmask)
{
    if(tree[u].empty())
    {
        encript[u+'a'] = bitmask;
        return;
    }
    dfs(tree[u][0], bitmask + '0');
    dfs(tree[u][1], bitmask + '1');
    return;
}

int main()
{
    cin >> s;
    n = (int)s.size();
    for(int i = 0; i < n; i++)
        cnt[s[i]-'a']++;
    for(int i = 0; i < 26; i++)
        if(cnt[i])
            pq.push({cnt[i], i});
    node = 26;
    while((int)pq.size() > 1)
    {
        ii a = pq.top(); pq.pop();
        ii b = pq.top(); pq.pop();
        if(a.second < b.second)
        {
            tree[node].push_back(a.second);
            tree[node].push_back(b.second);
        }
        else
        {
            tree[node].push_back(b.second);
            tree[node].push_back(a.second);
        }
        pq.push({(a.first + b.first), node++});
    }
    dfs(node - 1, "");
    
    cout << "Huffman Coding\n";
    for(auto it : encript)
        cout << it.first << ' ' << it.second << '\n';
    
    return 0;
}
