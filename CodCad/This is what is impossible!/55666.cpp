#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

bool ep[1001][1001];
int pd[1001][1001];

ii coin(int troco, vector<int> &m)
{
	for(int i = 0; i < m.size(); i++)
	{
		for(int j = 0; j <= troco; j++)
		{
			if(!i)
			{
				if(j%m[i] == 0)
					ep[i][j] = 1, pd[i][j] = j/m[i];
				else
					ep[i][j] = 0;
			}
			else if(m[i] <= j)
			{
				if(ep[i-1][j] or ep[i][j-m[i]])
				{
					if(ep[i-1][j] and ep[i][j-m[i]])
						pd[i][j] = min(pd[i-1][j], pd[i][j-m[i]]+1);
					else if(ep[i-1][j])
						pd[i][j] = pd[i-1][j];
					else
						pd[i][j] = pd[i][j-m[i]]+1;
					ep[i][j] = 1;
				}
				else
					ep[i][j] = 0;
			}
			else if(ep[i-1][j])
			{
				pd[i][j] = pd[i-1][j];
				ep[i][j] = 1;
			}
			else
				ep[i][j] = 0;
		}
	}
	return ii(ep[m.size()-1][troco], pd[m.size()-1][troco]);
}

int answer(int q, int x)
{
	int ans = 0;
	for(int i = 1; i < x; i++)
		if(!ep[q][i])
			ans++;	
	return ans;
}

int main()
{	
	int n, troco;
	vector<int> moeda;

	cin >> n >> troco;
	moeda.resize(n);
	for(int &p : moeda)
		cin >> p;
	ii ans = coin(troco, moeda);
	cout << answer(moeda.size()-1, troco) << '\n';

	return 0;
}