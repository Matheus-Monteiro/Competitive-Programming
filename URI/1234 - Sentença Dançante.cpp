// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sentença Dançante
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1234

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	string str;
	bool aux;

	while(getline(cin, str))
	{
		aux = true;
		for(int i = 0; i < str.size(); i++)
		{

			if(str[i] == ' ') {}

			else if(aux)
			{
				str[i] = toupper(str[i]);
				aux = false;
			}

			else
			{
				str[i] = tolower(str[i]);
				aux = true;
			}
		}
		cout << str << endl;
	}
	return 0;
}

