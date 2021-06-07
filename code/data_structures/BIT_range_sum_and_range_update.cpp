#include <bits/stdc++.h>
const int MAX = 1e5;

using namespace std;

struct BIT {

	int N;
	int BIT1[MAX];
	int BIT2[MAX];

	BIT(int M) {
		N = M;
	}

	void add(int *b, int pos, int x) {
		while(pos <= N) b[pos] += x, pos += pos&-pos;
	}

	void range_add(int l, int r, int x) {
		add(BIT1, l, x);
		add(BIT1, r + 1, -x);
		add(BIT2, l, x * (l - 1));
		add(BIT2, r + 1, -x * r);
	}

	int sum(int *b, int pos) {
		int s = 0;
		while(pos) s += b[pos], pos -= pos&-pos;
		return s;
	}

	int prefix_sum(int pos) {
		return sum(BIT1, pos) * pos - sum(BIT2, pos);
	}

	int range_sum(int l, int r) {
		return prefix_sum(r) - prefix_sum(l - 1);
	}
};

int main() {

	int n, q;
	cin >> n >> q;

	BIT B(n);
	
	while(q--) {
		int o, l, r, x;
		cin >> o >> l >> r;
		if(o == 1) {
			cout << B.range_sum(l, r) << '\n';
		} else {
			cin >> x;
		   	B.range_add(l, r, x);	
		}	
	}

	return 0;
}
