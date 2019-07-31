#include <bits/stdc++.h>
#define endl '\n'
#define MAX 105

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int a[MAX][MAX], b[MAX][MAX], n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
		
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> b[i][j];
		
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = a[i][j] + b[i][j];
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j];
			if(j < n-1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}