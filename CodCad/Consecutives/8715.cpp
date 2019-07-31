#include <bits/stdc++.h>
#define MAX 10100
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	long v[MAX], aux;
	int n, cont = 0;
	vector<int> r;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	aux = v[0];
	
	for(int i = 0; i < n; i++){
		if(aux == v[i])
			cont++;
		else
		{	
			r.push_back(cont);
			cont = 1;
			aux = v[i];
		}
		if(i == n-1)
			r.push_back(cont);
	}
	int maior = 0;
	for(int i = 0; i < r.size(); i++){
		if(maior < r[i])
			maior = r[i];
	}
	
	cout << maior << endl;
	
	return 0;
}