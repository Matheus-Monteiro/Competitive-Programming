#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int trie[MAX][26], cnt[MAX], tsz = 1;
bool leaf[MAX];

void insert(string s)
{
    int cur = 1;
    cnt[cur]++;
    for(int i = 0; i < s.size(); i++)
    {
        int a = s[i] - 'a';
        if(!trie[cur][a]) trie[cur][a] = ++tsz;
        cur = trie[cur][a];
        cnt[cur]++;
    }
    leaf[cur] = true;
}

bool find(string s)
{
    int cur = 1;
    for(int i = 0; i < s.size(); i++)
    {
        int a = s[i] - 'a';
        if(!trie[cur][a] or !cnt[cur])
            return false;
        cur = trie[cur][a];
    }
    return leaf[cur] and cnt[cur];
}

int remove(string s)
{
    int cur = 1;
    for(int i = 0; i < s.size(); i++)
    {
        int a = s[i] - 'a';
        cnt[cur]--;
        cur = trie[cur][a];
    }
    leaf[cur] = false;
    cnt[cur]--;
}

int main()
{	
    string s;
    int n, o;
    while(cin >> o >> s)
    {
        if(o == 1)
            cout << (find(s) ? "found\n" : "not found\n");
        else if(o == 2)
            insert(s);
        else
            remove(s);
    }

	return 0;
}
