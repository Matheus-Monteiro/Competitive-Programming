// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Conjuntos Bons e Ruins
// Nível: 4
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2087

#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *children[26];
    bool isLeaf;
    TrieNode(){
        this->isLeaf = false;
        for(int i = 0; i < 26; i++)
            this->children[i] = nullptr;
    }
};

bool insert(TrieNode *root, string s){
    int index, cont = 0;
    bool ok = false;
    TrieNode *node = root;
    for(int level = 0; level < s.size(); level++){
        index = s[level] - 'a';
        if(!node->children[index])
            node->children[index] = new TrieNode();
        else{
            cont++;
            if(!ok and node->children[index]->isLeaf) ok = true;
        }
        node = node->children[index];
    }
    node->isLeaf = true;
    return (cont == s.size() or ok);
}

int main(){
    int n;
    bool ok, flag;
    string s;
    TrieNode *root;

    while(cin >> n and n){
        root = new TrieNode();
        flag = true;
        while(n--){
            cin >> s;
            if(flag)
                ok = insert(root, s);
            if(ok and flag) flag = false;
        }
        cout << (flag ? "Conjunto Bom" : "Conjunto Ruim") << '\n';
        delete root;
    }

    return 0;
}
