#include <bits/stdc++.h>
using namespace std;

int na, nb, m, tempo = 1;
int b[105];
int cor[105];
vector<int> G[105];

bool kuhn(int u)
{
	if(cor[u] == tempo)
		return 0;
	cor[u] = tempo;
//random_shuffle(G[u].begin(), G[u].end(), [](int x){ return rand() % x; });
	for(const int &v : G[u])
		if(!b[v] or kuhn(b[v]))
			return b[v] = u;
	return 0;
}

int main()
{
	//srand(time(NULL));
	cin >> na >> nb >> m;
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v + na);
	}
	tempo = 1;
	int ans = 0;
	for(int i = 1; i <= na; i++)
		ans += kuhn(i), tempo++;
	cout << "MCBM = " << ans << '\n';
	for(int i = nb + 1; i <= na + nb; i++)
		if(b[i])
			cout << b[i] << ' ' << i - na << '\n';
	
    	return 0;
} 
