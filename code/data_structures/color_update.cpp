#include <bits/stdc++.h>
using namespace std;

#define bug(x) cout << #x << "  >>>>>>>  " << x << '\n'
#define _ << " , " <<
#define INF 0x3f3f3f3f

#define ii pair<int, int>
#define fi first
#define se second

struct Color {
	int x;
	Color(int _x) : x(_x) {}
	Color() : x(-1) {}
	bool operator<(const Color &c) const {
		return x < c.x;
	}
};

#define iic pair<pair<int, int>, Color>
#define defaut_color Color(-1)

struct ColorUpdate {
	set<iic> intervals;

	ColorUpdate(int begin = -INF, int end = INF) {
		intervals.insert( { {begin, end}, defaut_color } );
	}

	void paint(int l, int r, Color c = defaut_color) {
		if(l > r) return;

		auto a = prev(intervals.upper_bound({{l, INF}, INF}));
		auto b = prev(intervals.upper_bound({{r, INF}, INF}));

		int l1 = a->fi.fi, r1 = l - 1;
		Color c1 = a->se;
		int l2 = r + 1, r2 = b->fi.se;
		Color c2 = b->se;

		intervals.erase(a, next(b)); 

		if(l1 <= r1) intervals.insert({{l1, r1}, c1});
		if(l2 <= r2) intervals.insert({{l2, r2}, c2});
		if(l <= r) intervals.insert({{l, r}, c});
		
		// printall();
	}

	Color get_color_of(int x) {
		return prev(intervals.upper_bound({{x, INF}, INF}))->se;
	}

	// true if x is in some interval
	bool find(int x) {
		auto a = intervals.upper_bound({{x, INF}, INF});
		if(a == intervals.begin()) return false;
		a--;   
		if(a->fi.fi > x or a->fi.se < x) return false;
		return true;
	}

	ii get_interval_of(int x) {
		if(!find(x)) return {-INF, INF};
		return prev(intervals.upper_bound({{x, INF}, INF}))->fi;
	}

	ii get_interval_of(int l, int r) {
		if(!find(l)) return {-INF, INF};
		ii i = get_interval_of(l);
		if(i.fi <= r and r <= i.se) return i;
		return {-INF, INF};
	}

	// x will be on the left side
	void cut_at(int x) {
		if(!find(x)) return;

		auto a = prev(intervals.upper_bound({{x, INF}, INF}));

		Color c = a->se;

		int l1 = a->fi.fi, r1 = x;
		int l2 = x + 1, r2 = a->fi.se;
	
		intervals.erase(a);

		if(l1 <= r1) intervals.insert({{l1, r1}, c});
		if(l2 <= r2) intervals.insert({{l2, r2}, c});
	}

	void remove_interval(int l, int r) {
		cut_at(l - 1);
		cut_at(r);

		auto a = prev(intervals.upper_bound({{l, INF}, INF}));
		auto b = prev(intervals.upper_bound({{r, INF}, INF}));

		intervals.erase(a, next(b)); 
	}

	void remove_at(int x) {
		remove_interval(x, x);
	}

	void p_interval(iic i) {
		cout << "elements from " << i.fi.fi << " to " << i.fi.se;
		cout << " have color " << i.se.x << endl;
	}

	void printall() {
		cout << "\n\n\nColor Of The Elements:\n";
		for(auto it : intervals)
			p_interval(it);
		cout << endl << endl;
	}
};

int32_t main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ColorUpdate C(1, 100);

	for(int i = 3; i <= 50; i += 10)
		C.cut_at(i);

	C.remove_interval(16, 57);

	C.remove_at(100);
	C.remove_at(1);
	C.remove_at(2);
	C.remove_at(3);

	C.cut_at(20);

	C.printall();

	return 0;
}