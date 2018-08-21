#include<bits/stdc++.h>
using namespace std;
 
vector<int> G[10000]; // arvore
 
int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++)
		cin >> A[i];
 
 
	//construindo a cartesian tree em O(N)
	vector<int> parent(n, -1); // parent[v] = u significa que u é pai de v
	stack<int> s;
	for(int i = 0; i < n; i++)
	{
		int last = -1;
		while(!s.empty() and A[s.top()] >= A[i])
		{
		    last = s.top();
		    s.pop();
		}
		if(!s.empty())
		    parent[i] = s.top();
		if(last >= 0)
		    parent[last] = i;
		s.push(i);
	}
 
 
	int root = -1; // raiz da arvore
	for(int i = 0; i < n; i++)
		if(parent[i] == -1)
			root = i;
		else
			G[parent[i]].pb(i);
	for(int i = 0; i < n; i++)
		cout << parent[i] << ' ';
	puts("");
 
 	// para encontrar o RMP na range [L, R], basta
 	// achar o LCA entre L e R, e A[LCA(L, R)] é a resposta
 
	return 0;
}


