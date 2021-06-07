#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

int main() {
    int n = rand(4, 20);
	cout << n << endl;
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; i++)
        edges.emplace_back(rand(1, i - 1), i);
   
   	// re-naming vertices	
    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i)
        perm[i] = i;
    
    // random order of labels
	shuffle(perm.begin() + 1, perm.end(), rng);
    // random order of edges
	shuffle(edges.begin(), edges.end(), rng);
    
    for(auto [u, v] : edges) {
		// random order of two vertices
        if(rng() % 2) swap(u, v);
        cout << perm[u] << ' ' << perm[v] << endl;
    }

	return 0;
}
