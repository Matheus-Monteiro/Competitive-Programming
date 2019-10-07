#include <bits/stdc++.h>
using namespace std;

void lis(vector<int> &arr)
{
	vector<int> pilha;
	int pai[1000], pos[1000];
	for(int i = 0; i < arr.size(); i++)
	{
		int p = int(upper_bound(pilha.begin(),
			 pilha.end(), arr[i]) - pilha.begin());
		if(p == pilha.size())
			pilha.push_back(arr[i]);
		else
			pilha[p] = arr[i];
		pos[p] = i;
		if(!p)
			pai[i] = -1;
		else
			pai[i] = pos[p - 1];
	}
	vector<int> L;
	int aux = pos[pilha.size() - 1];
	cout << pilha.size() << '\n';
	while(aux != -1)
	{
		L.push_back(arr[aux]);
		aux = pai[aux];
	}
	reverse(L.begin(), L.end());
	for(const int &w : L)
		cout << w << ' ';
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int &w : arr) 
		cin >> w;
	lis(arr);
	
	return 0;
}
