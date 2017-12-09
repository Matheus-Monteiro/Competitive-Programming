// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dividindo a Coca
// Nível: 4
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1549

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-8;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
//#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, l, b, B, H; 

double area(double h, double raio)
{
    return (acos(-1)*h*(raio*raio + raio*b + b*b))/3.0;
}

double buscab()
{
    double ini = 0.0, fim = H, m, a = (double)l/(double)n;
    double rai = b, rai2 = B;
    REP(i, 200)
    {
        m = (ini + fim) / 2.0;
        double raio = (rai + rai2) / 2.0;
        double A = area(m, raio);
        //if(A > ((double)l/(double)n))
        if(A-a > EPS)
            fim = m, rai2 = raio;
        else
            ini = m, rai = raio;        
    }
    return m;
}

int main()
{
	int t;
	
	cin >> t;
	while(t--)
	{
        cin >> n >> l >> b >> B >> H;
        cout << fixed << setprecision(2) << buscab() << '\n';
	}

	return 0;
}
