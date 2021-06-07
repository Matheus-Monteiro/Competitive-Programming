 /*
 	contar a quantidade de numeros na range [1, b]
 	que sao multiplos de pelo menos um numero na range [1, a]
 */

#include <bits/stdc++.h>
using namespace std;
#define bug(x) cout << #x << "  >>>>>>>  " << x << '\n'
#define _ << " , " <<
#define int long long
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
#define ii pair<int, int>
#define fi first
#define se second
#define SZ(v) (int)v.size()
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
const long long MAX = (long long)1e15; //2 * 10^5
const int MOD = 1000000007; //10^9 + 7
const int OO = 0x3f3f3f3f;//3f3f3f3f;
const double EPS = 1e-9;  //10^-9
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127};
vector<vector<ii>> lista; 

void add(int id)
{
	vector<ii> aux;
	for(int k = 0; k < id; k++)
	{
		int i = SZ(lista[k]) - 1;
		while(i >= 0 and MAX / lista[k][i].fi / prime[id] == 0) i--;
		for(int j = 0; j <= i; j++)
			aux.push_back({lista[k][j].fi * prime[id], !lista[k][j].se});
	}
	aux.push_back({prime[id], 1});
	sort(aux.begin(), aux.end());
	lista.push_back(aux);	
}

int32_t main()
{
	for(int i = 0; i < SZ(prime); i++)
		add(i);
		
	int t;
	
	scanf(" %lld", &t);
	
	while(t--)
	{	
		int a, b;
		
		scanf(" %lld %lld", &a, &b);
		
		int ans = b / 2;
		int cnt_p = 0;
		
		for(int &w : prime) cnt_p += (w <= a);
		
		for(int i = 0; i < cnt_p; i++)
		{
			for(int j = 0; j < SZ(lista[i]); j++)
			{
				if(lista[i][j].fi > b) break;
				if(lista[i][j].se) ans += (b / lista[i][j].fi + 1) / 2;
				else ans -= (b / lista[i][j].fi + 1) / 2;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
