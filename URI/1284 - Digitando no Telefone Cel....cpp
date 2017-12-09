// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Digitando no Telefone Cel...
// Nível: 6
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1284

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

void insert(TrieNode *root, string s)
{
    TrieNode *node = root;
    int index;
    for(int i = 0; i < s.size(); i++)
    {
        index = s[i] - 'a';
        if(node->childreen.find(index) == node->childreen.end())
            node->childreen[index] = new TrieNode();
        node = node->childreen[index];
    }
    node->isLeaf = true;
}

int search(TrieNode *root, string s)
{
    TrieNode *node = root->childreen[s[0]-'a'];
    int ans = 1;
    for(int i = 1; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if(node->childreen.size() > 1 or node->isLeaf)
            ans++;
        node = node->childreen[index];
    }
    return ans;
}

int main()
{
    int n;
    vector<string> v;
    char c[100];
    string s;
    
    while(~scanf("%d", &n))
    {
        TrieNode *root = new TrieNode();
        while(n--)
        {
            scanf("%s", c);
            s = string(c);
            insert(root, s);
            v.push_back(s);
        }
        int cont = 0;
        for(int i = 0; i < v.size(); i++)
            cont += search(root, v[i]);
        printf("%.2lf\n", (double)cont/(double)v.size());
        v.clear();
    }
    return 0;
}
