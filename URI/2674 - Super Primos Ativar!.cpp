// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Super Primos: Ativar!
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2674

#include <bits/stdc++.h>
using namespace std;

const int OO = 0x3f3f3f3f;
const int MAX = 1e5 + 10;
const double EPS = 1e-8;

#define bug(x) cout << #x << ' ' << x <<< '\n';
#define FOR(i, a, n) for(int i = 0; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<int> primes;
bitset<MAX> e_composto;

void crivo()
{
    e_composto[1] = 1;
    primes.pb(-1);
    for(int i = 2; i <= MAX; i++)
        if(!e_composto[i])
        {
            primes.pb(i);
            for(int j = 2; i*j <= MAX; j++)
                e_composto[i*j] = 1;
         }   
}

bool isPrime(int x)
{
    int b = 1, e = primes.size()-1, m;
    while(b <= e)
    {
        m = (b+e)/2;
        if(primes[m] == x)
            return true;
        if(primes[m] > x)
            e = m - 1;
        else
            b = m + 1;
    }
    return false;
}

bool solve(int n)
{
    int aux;
    while(n)
    {
        aux = n%10;
        if(!isPrime(aux)) return false;
        n = n/10;
    }
    return true;
}

int main()
{
    int n;
    crivo();
    while(cin >> n)
    {
        if(isPrime(n))
        {
            if(solve(n))
                cout << "Super\n";
            else
                cout << "Primo\n";
        }
        else
            cout << "Nada\n";
    }
    return 0;
}
