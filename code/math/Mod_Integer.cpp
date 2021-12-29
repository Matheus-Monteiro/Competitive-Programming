#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct ModInt {
	const static T MOD = 1000000007; //1e9 + 7
	
	T v; explicit operator T() const { return v; }

	ModInt() { v = 0; }
	ModInt(T _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const ModInt& a, const ModInt& b) { 
		return a.v == b.v; }
	friend bool operator!=(const ModInt& a, const ModInt& b) { 
		return !(a == b); }
	friend bool operator<(const ModInt& a, const ModInt& b) { 
		return a.v < b.v; }
   
	ModInt& operator+=(const ModInt& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	ModInt& operator-=(const ModInt& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	ModInt& operator*=(const ModInt& m) { 
		v = v*m.v%MOD; return *this; }
	ModInt& operator/=(const ModInt& m) { return (*this) *= inv(m); }
	friend ModInt pow(ModInt a, T p) {
		assert(p >= 0);
		ModInt ans = 1; 
		while(p) {
			if(p & 1) ans *= a;
			a *= a;
			p /= 2;
		}
		return ans;
	}
	friend ModInt inv(const ModInt& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	ModInt operator-() const { return ModInt(-v); }
	ModInt& operator++() { return *this += 1; }
	ModInt& operator--() { return *this -= 1; }
	ModInt operator++(int) { ModInt temp; temp.v = v++; return temp; }
	ModInt operator--(int) { ModInt temp; temp.v = v--; return temp; }
	friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
	friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
	friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
	friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const ModInt& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, ModInt& m) {
		T x; is >> x;
		m.v = x;
		return is;
	}
};

int main(){
	ModInt<long long> x = 5;
	cout << x << ' ' << inv(x) << '\n';
	cout << x.MOD << '\n';

	return 0;
}
