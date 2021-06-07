#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	map<int, TrieNode*> childreen;
	bool isLeaf;
	TrieNode()
	{
		isLeaf = false;
	}
};

void inserir(TrieNode *root, string s)
{
	TrieNode *node = root;
	for(int i = 0; i < s.size(); i++)
	{
		int index = s[i] - 'a';
		if(node->childreen.find(index) == node->childreen.end())
			node->childreen[index] = new TrieNode();
		node = node->childreen[index];
	}
	node->isLeaf = true;
}

bool buscar(TrieNode *root, string s)
{
	TrieNode *node = root;
	for(int i = 0; i < s.size(); i++)
	{
		int index = s[i] - 'a';
		if(node->childreen.find(index) == node->childreen.end())
			return false;
		node = node->childreen[index];
	}	
	return node->isLeaf;
}

bool remover(TrieNode *node, string s, int level)
{
	if(node != nullptr)
		if(s.size() == level)
		{
			if(node->isLeaf)
			{
				node->isLeaf = false;
				return !node->childreen.size();
			}
		}
		else
		{
			int index = s[level] - 'a';
			if(remover(node->childreen[index], s, level+1))
			{
				delete node->childreen[index];
				node->childreen.erase(index);
				return !node->childreen.size();
			}
		}
	return false;
}

int main()
{
	TrieNode *root = new TrieNode();

	inserir(root, "abc");
	inserir(root, "abd");
	inserir(root, "cfa");
	remover(root, "abc", 0);
	printf(buscar(root, "abc") ? "yes\n" : "no\n");
	printf(buscar(root, "abd") ? "yes\n" : "no\n");
	
	return 0;
}
