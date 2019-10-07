#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3;

int n, aux, BIT[MAX][MAX];

void update(int x, int y, int value)
{
	for(int i = x; i <= n; i += i&-i)
		for(int j = y; j <= n; j += j&-j)
			BIT[i][j] += value;
}

int query(int x, int y)
{
	int sum = 0;
	for(int  i = x; i > 0; i -= i&-i)
		for(int j = y; j > 0; j -= j&-j)
			sum += BIT[i][j];
	return sum;
}

int queryInRectangle(int x1, int y1, int x2, int y2)
{
	int sum = 0;
	sum += query(max(x1, x2), max(y1, y2));
	sum -= query(max(x1, x2), min(y1, y2) - 1);	
	sum -= query(min(x1, x2) - 1, max(y1, y2));
	sum += query(min(x1, x2) - 1, min(y1, y2) - 1);	
	return sum;	
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> aux, update(i, j, aux);
	int x1, y1, x2, y2;
	while(cin >> x1 >> y1 >> x2 >> y2)
		cout << queryInRectangle(x1, y1, x2, y2) << '\n';

	return 0;
}
