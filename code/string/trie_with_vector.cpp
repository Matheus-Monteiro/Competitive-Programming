#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	int child[26], size, cnt;
	TrieNode()
	{
		memset(child, 0, sizeof(child));
		size = cnt = 0; 
	}
};

vector<TrieNode> trie;

void init()
{ 
	trie.clear();
	trie.push_back(TrieNode());
}

void add(string s)
{
	int root = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		int index = s[i] - 'a';
		if(trie[root].child[index] == 0)
		{
			trie[root].child[index] = trie.size();
			trie.push_back(TrieNode());
		}
		root = trie[root].child[index];
		trie[root].size++;
	}
	trie[root].cnt++;
}

void sub(string s)
{
	int root = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		int index = s[i] - 'a';
		root = trie[root].child[index];
		trie[root].size--;
	}
	trie[root].cnt--;
}

int query(string s)
{
	int root = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		int index = s[i] - 'a';
		if(!trie[trie[root].child[index]].size)
			return false;
		root = trie[root].child[index];
	}
	return trie[root].cnt;
}

int main()
{
	string s;
	int o;
	init();
	while(cin >> o >> s)
	{
		if(o == 1) add(s);
		else if(o == 2) sub(s);
		else cout << query(s) << '\n';
	}
	
	return 0;
}
