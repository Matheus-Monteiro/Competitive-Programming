// O(1) complexity for all operations, except for clear,
// which could be done by creating another deque and using swap
#include <bits/stdc++.h>
using namespace std;

struct MaxQueue 
{
	int plus = 0;
	deque<pair<int, int>> dq;

	bool empty() { return dq.size() == 0; }
	void clear() { plus = 0; dq.clear(); }
	void add(int x) { plus += x; } // Adds x to every element in the queue
	int max() {  return dq.begin()->first + plus;  } 
	// Returns the maximum element in the queue

	void push(int x) 
	{
		x -= plus;
		int amt = 0;
		while (dq.size() and dq.back().first <= x)
			amt += dq.back().second + 1, dq.pop_back();
		dq.push_back({ x, amt });
	}

	void pop() 
	{
		if (dq.empty()) return;
		if (!dq.front().second) dq.pop_front();
		else dq.front().second--;
	}
};

int main()
{
	int n, aux;
	MaxQueue Q;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int aux;
		cin >> aux;
		Q.push(aux);
		cout << "max " << Q.max() << '\n';
	}
	return 0;
}
