// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Despojados
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2661

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 10000;

vector<ll> primes;
vector<ll> factors;
bitset<MAX> compound;

void sieve()
{
    compound[1] = 1;
    for(int i = 2; i <= MAX; i++)
        if(!compound[i])
        {
            primes.push_back(i);
            for(int j = 2; i*j <= MAX; j++)
                compound[i*j] = 1;
        }
}

void primesFactors(ll n)
{
    int pIdx = 0;
    ll p = primes[pIdx++];
    while(p*p <= n)
    {
        while(n%p == 0)
        {
            n /= p;
            factors.push_back(p);
        }
        if(primes.size() == pIdx) break;
        p = primes[pIdx++];
    }
    if(n != 1)
        factors.push_back(n);
}

int numberOfDifferentFactors(ll n)
{
    int pIdx = 0;
    ll p = primes[pIdx++];
    int ans = 0;
    while(p*p <= n)
    {
        bool fl = false;
        while(n%p == 0)
        {
            if(fl) return -1;
            fl = true;
            n /= p;
            ans++;
        }
        if(primes.size() == pIdx) break;
        p = primes[pIdx++];
    }
    if(n != 1)
        ans++;
    return ans < 2 ? -1 : ans;
}

int main()
{
    ll n;
    int ans;
    cin >> n;
    sieve();
    primesFactors(n);
    set<ll> s;
    ans = 0;
    for(int i = 1; i <= (1 << factors.size()); i++)
    {
        ll p = 1;
        for(int j = 0; j < factors.size(); j++)
            if(i&(1<<j))
                p *= factors[j];
        if(s.find(p) == s.end())
        {
            if(numberOfDifferentFactors(p) != -1)
                ans++;
            s.insert(p);
        }
    }
    cout << ans << '\n'; 
        
    return 0;
}
