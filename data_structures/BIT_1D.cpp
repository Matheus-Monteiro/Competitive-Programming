#include <bits/stdc++.h>
using namespace std;

int aux, n, arr[1000], BIT[1000];

// construir uma BIT a partir de um array em O(N)
void build()  {
	for(int i = 1; i <= n; i++) {
		BIT[i] += arr[i];
		if(i + (i & -i) <= n)
			BIT[i + (i & -i)] += BIT[i];
	}
}

// construir o array que gera a BIT a partir de uma BIT em O(N)
void buildArray()  {
	for(int i = n; i >= 1; i--)
		if(i + (i & -i) <= n)
			BIT[i + (i & -i)] -= BIT[i];
}

int sum(int x) {
    int s = 0;
    while(x) s += BIT[x], x -= x&-x;
    return s;
}

void update(int x, int value) {
    while(x <= n) BIT[x] += value, x += x&-x;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        update(i, aux);
    }
    int a, b;
    cin >> a >> b;
    cout << sum(b)-sum(a-1) << '\n';
    
    return 0;
}
