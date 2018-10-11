#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	map<int, TrieNode*> childreen;
	int isLeaf;
	TrieNode()
	{
		isLeaf = 0;
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
	node->isLeaf++;
}

int buscar(TrieNode *root, string s)
{
	TrieNode *node = root;
	for(int i = 0; i < s.size(); i++)
	{
		int index = s[i] - 'a';
		if(node->childreen.find(index) == node->childreen.end())
			return 0;
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
				node->isLeaf--;
				return !node->isLeaf and !node->childreen.size();
			}
		}
		else
		{
			int index = s[level] - 'a';
			if(remover(node->childreen[index], s, level+1))
			{
				delete node->childreen[index];
				node->childreen[index] = nullptr;
				node->childreen.erase(index);
				return !node->isLeaf and !node->childreen.size();
			}
		}
	return false;
}

int main()
{
	TrieNode *root = new TrieNode();

	inserir(root, "abc");
	inserir(root, "abd");
    inserir(root, "abc");
    inserir(root, "abc");
    inserir(root, "abc");
    inserir(root, "abcd");
	remover(root, "abc", 0);
	remover(root, "abc", 0);
	remover(root, "abc", 0);
	remover(root, "abc", 0);
	cout << buscar(root, "abc") << '\n';
	cout << buscar(root, "abcd") << '\n';
	
	return 0;
}