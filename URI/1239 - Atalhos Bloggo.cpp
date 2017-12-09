// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Atalhos Bloggo
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1239

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str, aux;	
	
	while(getline(cin, str))
	{
		bool fl1 = 0, fl2 = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '_')
			{
				if(!fl1)
				{
					fl1 = 1;
					aux = str.substr(0, i);
					str = aux + "<i>" + str.substr(i+1);
				}
				else
				{
					fl1 = 0;
					aux = str.substr(0, i);
					str = aux + "</i>" + str.substr(i+1);
				}
			}
			if(str[i] == '*')
			{
				if(!fl2)
				{
					fl2 = 1;
					aux = str.substr(0, i);
					str = aux + "<b>" + str.substr(i+1);
				}
				else
				{
					fl2 = 0;
					aux = str.substr(0, i);
					str = aux + "</b>" + str.substr(i+1);
				}
			}
		}
		printf("%s\n", str.c_str());
	}
	
	return 0;
}
