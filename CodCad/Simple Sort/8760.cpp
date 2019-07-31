#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){ 
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	int v[100100];
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v, v+n);
	
	for(int i = 0; i < n; i++){
		cout << v[i];
		if(i < n-1)
			cout << " ";
	}
	cout << endl;

	return 0;
}