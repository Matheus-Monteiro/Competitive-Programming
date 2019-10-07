#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e6 + 10; 

int n, x, weight[1005];
bool pd[MAX];
int ans[MAX];

void printAns(int m)
{
	cout << ans[m] << ' ';
	if(m - ans[m] > 0)
		printAns(m - ans[m]);
}

int main()
{	
	cin >> n >> x;
	int sum = 0;
	for(int i = 0; i < n; i++) cin >> weight[i], sum += weight[i];
	pd[0] = 1;
	for(int j = 0; j < n; j++)	
		for(int i = sum; i >= 0; i--)
			if(pd[i] and !pd[i + weight[j]])
			{
				ans[i + weight[j]] = weight[j];
				pd[i + weight[j]] = 1;
			}
			
	printAns(x);
	puts("");
		
	return 0;
} 
