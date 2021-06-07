#include <bits/stdc++.h>
using namespace std;
#define int long long
const int OO = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2000000;

typedef pair<int, int> ii;

int n, m, k;
vector<ii> G[MAX];
int cnt[MAX];

void dijkstra(int v) {
	priority_queue<ii> pq;
	pq.push({0, v});
	int c = 0;
	while(!pq.empty()) {
		int u = -pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		cnt[u]++;
		if(cnt[u] > k) continue;
			if(u == n - 1) {
				cout << d << ' ';
			if(++c == k) { cout << '\n'; return; }
		}
		for(auto [_d, w] : G[u])
			if(cnt[w] < k)
				pq.push({-(d + _d), -w});
    }
}

int32_t main() {
	cin >> n >> m >> k;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w; u--; v--;
		G[u].push_back({w, v});
	}
	dijkstra(0);
	
	return 0;
}
