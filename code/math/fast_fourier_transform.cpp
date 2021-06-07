#include <bits/stdc++.h>
 
using namespace std;
 
typedef complex<double> ftype;
const double pi = acos(-1);
const int maxn = 1 << 22;
ftype w[maxn];
 
void init()
{
    for(int i = 0; i < maxn; i++)
        w[i] = polar(1., 2 * pi / maxn * i);
}
 
template<typename T>
void fft(T *in, ftype *out, int n, int k = 1)
{
    if(n == 1)
    {
        *out = *in;
        return;
    }
    int t = maxn / n;
    n >>= 1;
    fft(in, out, n, 2 * k);
    fft(in + k, out + n, n, 2 * k);
    for(int i = 0, j = 0; i < n; i++, j += t)
    {
        ftype t = w[j] * out[i + n];
        out[i + n] = out[i] - t;
        out[i] += t;
    }
}
 
vector<ftype> evaluate(vector<int> p)
{
    while(__builtin_popcount(p.size()) != 1)
        p.push_back(0);
    vector<ftype> res(p.size());
    fft(p.data(), res.data(), p.size());
    return res;
}
 
vector<int> interpolate(vector<ftype> p)
{
    int n = p.size();
    vector<ftype> inv(n);
    fft(p.data(), inv.data(), n);
    vector<int> res(n);
    for(int i = 0; i < n; i++)
        res[i] = round(real(inv[i]) / n);
    reverse(begin(res) + 1, end(res));
    return res;
}
 
void align(vector<int> &a, vector<int> &b)
{
    int n = a.size() + b.size() - 1;
    while(a.size() < n)
        a.push_back(0);
    while(b.size() < n)
        b.push_back(0);
}
 
vector<int> poly_multiply(vector<int> a, vector<int> b)
{
    align(a, b);
    auto A = evaluate(a);
    auto B = evaluate(b);
    for(int i = 0; i < A.size(); i++)
        A[i] *= B[i];
    return interpolate(A);
}
 
const int base = 10;
vector<int> normalize(vector<int> c)
{
    int carry = 0;
    for(auto &it: c)
    {
        it += carry;
        carry = it / base;
        it %= base;
    }
    while(carry)
    {
        c.push_back(carry % base);
        carry /= base;
    }
    return c;
}
 
vector<int> multiply(vector<int> a, vector<int> b)
{
    return normalize(poly_multiply(a, b));
}
 
vector<int> faz(string s)
{
	vector<int> ans;
	for(char &c : s)
		ans.push_back(c-'0');
	return ans;
}
 
string multAB(string s1, string s2)
{
	if(s1 == "0" or s2 == "0")
		return "0";
	bool sinall;
	if(s1[0] == '-' and s2[0] == '-' or s1[0] != '-' and s2[0] != '-')
		sinall = true;
	else
		sinall = false;
	if(s1[0] == '-') s1[0] = '0';
	if(s2[0] == '-') s2[0] = '0';
	vector<int> A = faz(s1), B = faz(s2);
	A = normalize(A);
	B = normalize(B);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	auto C = multiply(A, B);
	while(C.back() == 0)
    	C.pop_back();
	reverse(C.begin(), C.end());
	string ans;
	ans += (!sinall ? "-" : "");
	for(int &c: C)
		ans += char(c + '0');
	return ans;
}

int main()
{
	int t;
    init();
 
    cin >> t;
    while(t--)
    {
		string s1, s2;
		cin >> s1 >> s2;// le os dois numeros como strings
		if(s1 == "0" or s2 == "0")
		{
			puts("0");
			continue;
		}
		vector<int> A = faz(s1), B = faz(s2);
		A = normalize(A);
		B = normalize(B);
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
 
		auto C = multiply(A, B);
 
		while(C.back() == 0)
        	C.pop_back();
		reverse(C.begin(), C.end());
		for(int &c: C)
			cout << c;
		puts("");
    }  
 
	/*
		init();
	    vector<int> a = {3, 4}, b = {2, 3};
		auto C = poly_multiply(a, b);
		int k = int(a.size() + b.size()) - 1;    
		for(int i = 0; i < k; i++)
    		cout << C[i] << "X^" << k-i-1 << (i < k-1 ? " + " : "\n");
	*/
 
   	return 0;
}



////////////////////////////////////////////////////////////



#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
const double PI = acos(-1);

struct T
{
	ld x, y;
	T() : x(0), y(0) {}
	T(ld a, ld b=0) : x(a), y(b) {}

	T operator/=(ld k) { x/=k; y/=k; return (*this); }
	T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
	T operator+(T a) const { return T(x+a.x, y+a.y); }
	T operator-(T a) const { return T(x-a.x, y-a.y); }
} a[1 << 23], b[1 << 23];

void fft(T* a, int n, int s)
{
	for (int i=0, j=0; i<n; i++)
	{
		if (i>j) swap(a[i], a[j]);
		for (int l=n/2; (j^=l) < l; l>>=1);
	}
	for(int i = 1; (1<<i) <= n; i++)
	{
		int M = 1 << i;
		int K = M >> 1;
		T wn = T(cos(s*2*PI/M), sin(s*2*PI/M));
		for(int j = 0; j < n; j += M)
		{
			T w = T(1, 0);
			for(int l = j; l < K + j; ++l)
			{
				T t = w*a[l + K];
				a[l + K] = a[l]-t;
				a[l] = a[l] + t;
				w = wn*w;
			}
		}
	}
}

void multiply(T* a, T* b, int n)
{
	fft(a,n,1);
	fft(b,n,1);
	for (int i = 0; i < n; i++)
		a[i] = a[i]*b[i];
	fft(a,n,-1);
	for (int i = 0; i < n; i++)
		a[i] /= n;
}
 
int main()
{
	int n, na, nb, c;
	cin >> na >> nb;
	n = na + nb;
	while(n&(n-1))
		n++;
	for(int i = n - na; i < n; i++)
	{
		cin >> c;
		a[i] = T(c);
	}
	for(int i = n - nb; i < n; i++)
	{
		cin >> c;
		b[i] = T(c);
	}
	multiply(a, b, n);
	for(int i = 0; i < n - 1; i++)
		cout << int(a[i].x + 0.5) << "X^"
		 << n - 2 - i << (i < n - 2 ? " + " : "");
	puts("");

	/*
		3 2
		1 0 0
		2 3
		0X^6 + 0X^5 + 0X^4 + 2X^3 + 3X^2 + 0X^1 + 0X^0
	*/

	return 0;
} 


////////////////////////////////////////////////////////////////
//contar quantos subarrays de soma diferentes existem usando FFT

#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
const long double PI = acos(-1);

struct T
{
	ld x, y;
	T() : x(0), y(0) {}
	T(ld a, ld b=0) : x(a), y(b) {}

	T operator/=(ld k) { x/=k; y/=k; return (*this); }
	T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
	T operator+(T a) const { return T(x+a.x, y+a.y); }
	T operator-(T a) const { return T(x-a.x, y-a.y); }
} a[16777219], b[16777219];

int pd[16777219];

void fft(T* a, int n, int s)
{
	for(int i=0, j=0; i<n; i++)
	{
		if (i>j) swap(a[i], a[j]);
		for (int l=n/2; (j^=l) < l; l>>=1);
	}
	for(int i = 1; (1<<i) <= n; i++)
	{
		int M = 1 << i;
		int K = M >> 1;
		T wn = T(cos(s*2*PI/M), sin(s*2*PI/M));
		for(int j = 0; j < n; j += M)
		{
			T w = T(1, 0);
			for(int l = j; l < K + j; ++l)
			{
				T t = w*a[l + K];
				a[l + K] = a[l]-t;
				a[l] = a[l] + t;
				w = wn*w;
			}
		}
	}
}

void multiply(T* a, T* b, int n)
{
	fft(a,n,1);
	fft(b,n,1);
	for (int i = 0; i < n; i++)
		a[i] = a[i]*b[i];
	fft(a,n,-1);
	for (int i = 0; i < n; i++)
		a[i] /= n;
}
 
int main()
{
	int k;
	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		int aux;
		cin >> aux;
		pd[i] = pd[i - 1] + aux;
	}
	if(k >= 10000)
	{
		for(int i = 0; i <= k; i++)
		{
			a[pd[i] + pd[k]].x = 1;
			b[pd[k] - pd[i]].x = 1;
		}
		int n = pd[k] + pd[k];
		n = 2 * n;
		while(n & (n - 1))
			n++;
		multiply(a, b, n);
		int ans = 0;
		for(int i = 0; i <= n; i++)
			if(int(a[i].x + 0.5) > 0 and (i - 2 * pd[k]) > 0)
				ans++;
		cout << ans << '\n';
	}
	else
	{
		int cnt = 0;
		unordered_set<int> ans1;
		for(int i = 1; i <= k; i++)
			for(int j = i; j <= k; j++)
				if(ans1.find(pd[j] - pd[i - 1]) == ans1.end())
				{
					ans1.insert(pd[j] - pd[i - 1]);
					cnt++;
				}
		cout << cnt << '\n';
	}
	// quantidade de subarrays com soma diferente
	
	return 0;
} 


////////////////////////////////////////////////////////////////////////////////////////


#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
const double PI = acos(-1);

struct T
{
	ld x, y;
	T() : x(0), y(0) {}
	T(ld a, ld b=0) : x(a), y(b) {}

	T operator/=(ld k) { x/=k; y/=k; return (*this); }
	T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
	T operator+(T a) const { return T(x+a.x, y+a.y); }
	T operator-(T a) const { return T(x-a.x, y-a.y); }
} a[1 << 20], b[1 << 20];

void fft(T* a, int n, int s)
{
	for (int i=0, j=0; i<n; i++)
	{
		if (i>j) swap(a[i], a[j]);
		for (int l=n/2; (j^=l) < l; l>>=1);
	}
	for(int i = 1; (1<<i) <= n; i++)
	{
		int M = 1 << i;
		int K = M >> 1;
		T wn = T(cos(s*2*PI/M), sin(s*2*PI/M));
		for(int j = 0; j < n; j += M)
		{
			T w = T(1, 0);
			for(int l = j; l < K + j; ++l)
			{
				T t = w*a[l + K];
				a[l + K] = a[l]-t;
				a[l] = a[l] + t;
				w = wn*w;
			}
		}
	}
}

void multiply(T* a, T* b, int n)
{
	fft(a,n,1);
	fft(b,n,1);
	for (int i = 0; i < n; i++)
		a[i] = a[i]*b[i];
	fft(a,n,-1);
	for (int i = 0; i < n; i++)
		a[i] /= n;
}
 
const int base = 10;
vector<int> normalize(vector<int> c)
{
    int carry = 0;
    for(auto &it: c)
    {
        it += carry;
        carry = it / base;
        it %= base;
    }
    while(carry)
    {
        c.push_back(carry % base);
        carry /= base;
    }
    return c;
}
 
vector<int> faz(string s)
{
	vector<int> ans;
	for(char &c : s)
		ans.push_back(c-'0');
	return ans;
}
 
string mul(string s1, string s2)
{
	vector<int> A = normalize(faz(s1));
	vector<int> B = normalize(faz(s2));

	int na = A.size(), nb = B.size();
	int n = na + nb;

	while(n&(n-1))
		n++;
	
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	while(A.size() < n) A.push_back(0);
	while(B.size() < n) B.push_back(0);
	
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	for(int i = 0; i < n; i++)
		a[i] = T(A[i]);
	for(int i = 0; i < n; i++)
		b[i] = T(B[i]);

	multiply(a, b, n);

	vector<int> r;
	for(int i = 0; i < n - 1; i++)
		r.push_back(a[i].x + 0.5);
	
	reverse(r.begin(), r.end());
	
	r = normalize(r);

	while(r.back() == 0)
        	r.pop_back();

	reverse(r.begin(), r.end());
	
	string ans;
	
	for(int &c: r)
		ans.push_back(c + '0');

	return ans;
}
 
int main()
{
	

	return 0;
} 

