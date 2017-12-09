// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Primo de Josephus
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1032

#include <bits/stdc++.h>
using namespace std;
 
vector<uint64_t> primes;
bool e_composto[1000000];
deque<uint64_t> l;

void crivo()
{ 
	e_composto[1] = 1;
	for(int i = 2; i <= 100000; i++)
	{
		if(!e_composto[i])
		{
			primes.push_back(i);
			for(int j = 2; i*j <= 100000; j++)
				e_composto[i*j] = 1;
			
		}
	}
}

uint64_t josephus()
{
    int i = 1, p = 2, k = 0;
    while(l.size() != 1)
    {
        k = (k + p - 1)%l.size();
        l.erase(l.begin()+k);
        p = primes[i++];
    }
    return l[0];
}

int main()
{
	crivo();
	int n;
	
	
	while(cin >> n and n)
	{
		for(int i = 1; i <= n; i++)
			l.push_back(i);
		cout << josephus() << '\n';
		l.clear();
	}	
    return 0;
}
