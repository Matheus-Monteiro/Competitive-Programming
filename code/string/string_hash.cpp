#include "bits/stdc++.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
struct StringHash {
    int n;
    string s;
    long long p = 1238473;
    long long mod = (1ll << 61) - 1;
    vector<long long> h, pot;
 
    long long mulmod(long long a, long long b) {
        long long q = (long long)((long double)a*b/mod);
        long long r = a * b - mod * q;
        while(r < 0) r += mod;
        while(r >= mod) r -= mod;
        return r;
        // return (a * (__int128)1 * b) % mod;
    }

    long long operator()(int l, int r) {
        if(!l) return h[r];
        long long hash_val = (h[r] - mulmod(h[l - 1], pot[r - l + 1]));
        if(hash_val < 0) hash_val += mod;
        return hash_val;
    }
 
    void build_hash() {
        h[0] = s[0];
        pot[0] = 1;
        for(int i = 1; i < n; ++i) {
            h[i] = (mulmod(h[i - 1], p) + s[i]);
            h[i] -= (h[i] >= mod ? mod : 0);
            pot[i] = mulmod(pot[i - 1], p);
        }
    }
 
    StringHash(string &_s) : n((int)_s.size()), s(_s) {
        h.resize(n);
        pot.resize(n);
        build_hash();
    }
};
 
bool equal_str(StringHash &a, int i, StringHash &b, int j, int size) {
    // assert(i + size - 1 < a.n and j + size - 1 < b.n);
    return a(i, i + size - 1) == b(j, j + size - 1);
}
 
int largest_common_prefix(StringHash &a, int la, int ha, StringHash &b, int lb, int hb) {
    int size_a = ha - la + 1, size_b = hb - lb + 1;
    int lo = 0, hi = min(size_a, size_b) + 1;
    while(lo < hi - 1) {
        int mid = (lo + hi) / 2;
        if(equal_str(a, la, b, lb, mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

int largest_common_suffix(StringHash &a, int la, int ha, StringHash &b, int lb, int hb) {
    int size_a = ha - la + 1, size_b = hb - lb + 1;
    int lo = 0, hi = min(size_a, size_b) + 1;
    while(lo < hi - 1) {
        int mid = (lo + hi) / 2;
        if(equal_str(a, ha - mid + 1, b, hb - mid + 1, mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

bool less_then(StringHash &a, int la, int ha, StringHash &b, int lb, int hb) {
    int size_a = ha - la + 1, size_b = hb - lb + 1;
    int sz = largest_common_prefix(a, la, ha, b, lb, hb);
    if(sz == size_a or sz == size_b) return size_a < size_b;
    return a.s[la + sz] < b.s[lb + sz];
}
 
string min_cyc_shift(string s) {
    int n = s.size();
    s += s;
    StringHash H(s);
    int best_i = 0;
    for(int i = 0; i < n; ++ i)
        if(less_then(H, i, i + n - 1, H, best_i, best_i + n - 1))
            best_i = i;
    return s.substr(best_i, n);
}
 
string longest_repeating_substring(string s) {
    StringHash h(s);
    int n = s.size();
    auto check = [&](int sz) {
        unordered_set<long long> buc;
        for(int i = 0; i <= n - sz; ++i) {
            long long hash_val = h(i, i + sz - 1);
            if(buc.count(hash_val))
                return hash_val;
            buc.insert(hash_val);
        }
        return -1ll;
    };
    int lo = 1, hi = n, str_sz = -1;
    long long hash_v = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        long long h_v = check(mid);
        if(h_v >= 0) lo = mid + 1, hash_v = h_v, str_sz = mid;
        else hi = mid - 1;
    }
    if(hash_v == -1) return "-1";
    for(int i = 0; i <= n - str_sz; ++i)
        if(h(i, i + str_sz - 1) == hash_v)
            return s.substr(i, str_sz);

    return "-1";
}
 
int32_t main() {
    fastio;
    
    return 0;
}