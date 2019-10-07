#include <bits/stdc++.h>
using namespace std;
 
// as posicoes de 0 ate 25 representam as letras
// de a ate z do alfabeto.
// a posicao 26 armazena quantas strings terminam
// nesse vertice.
// a posicao 27 armazena quantas strings passam 
// nesse vertice.
 
int trie[8000000][30], CUR = 1;
 
// fl eh zero se for uma operacao de inserir
// fl eh um se for uma operacao de buscar
int add(string &s, int fl)
{
	int root = 0;
	for(char &c : s)
	{
		if(trie[root][c - 'a'] == 0)
		{
			if(fl) return 0;
			trie[root][c - 'a'] = CUR++;
		}
		if(!fl) trie[root][27]++;
		root = trie[root][c - 'a'];
	}
	if(fl) return trie[root][26];
	trie[root][26]++;
	return 1;
}
 
void sub(string &s)
{
	int root = 0;
	for(char &c : s)
		if(trie[root][c - 'a'] and trie[root][27])
		{
			trie[root][27]--;
			root = trie[root][c - 'a'];
		}
	trie[root][26]--;
}
 
int main()
{
	int q;
 
	cin >> q;
 
	while(q--)
	{
		int o;
		string s;
		cin >> o >> s;
		if(o == 1) add(s, 0);
		else if(o == 2) puts(add(s, 1) ? "existe" : "nao existe");
		else sub(s);
	}	
 
	return 0;
}
