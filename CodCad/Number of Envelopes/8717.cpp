#include <bits/stdc++.h>
#define MAX 1010
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int v[MAX], menor = 999999999;
	int n;;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	for(int i = 0; i < n; i++)
		if(v[i] < menor)
			menor = v[i];
	
	cout << menor << endl;
		
	return 0;
}