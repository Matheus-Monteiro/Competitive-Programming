#include <bits/stdc++.h>
using namespace std;
#define bug(x) cout << #x << "  >>>>>>>  " << x << '\n'
#define _ << " , " <<
//#define int long long
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
#define ii pair<int, int>
#define fi first
#define se second
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
const int MAX = 20002; //2 * 10^5
const int MOD = 1000000007; //10^9 + 7
const int OO = 0x3f3f3f3f; // 0x3f3f3f3f;
const double EPS = 1e-9;  //10^-9
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, S;
int B[205];
int C[205];
int V[3500];
int W[3500];
int ID[3500];
int id = 1;
int dp[MAX];
int linha[70][MAX], T[70][MAX];
int L[70];

void add(int j)
{
	int sum = 0;
	for(int k = 0; sum + (1 << k) <= C[j]; sum += (1 << k), k++)
	{
		V[id] = B[j] * (1 << k);
		W[id] = (1 << k);
		ID[id] = j;
		id++;
	}
	int r = C[j] - sum;
	if(r > 0)
	{
		V[id] = B[j] * r;
		W[id] = r;
		ID[id] = j;
		id++;
	}
}

int32_t main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> B[i];
	for(int i = 1; i <= n; i++) cin >> C[i];
	for(int i = 1; i <= n; i++) add(i);
	cin >> S;

	for(int j = 1; j <= S; j++)
		dp[j] = OO;
		
	int cnt = 0, k = -1, sq = max(10, (int)sqrt(id * 1.));
	for(int i = 1; i < id; i++)
	{
		if(cnt % sq == 0)
		{
			cnt = 0;
			k++;
			for(int j = 0; j <= S; j++)
				linha[k][j] = dp[j];
			L[k] = i - 1;
		}
		for(int j = S; j >= V[i]; j--)
			dp[j] = Min(dp[j - V[i]] + W[i], dp[j]);
		cnt++;
	}
	
	int last_raw = id - 1, s = S;
	
	vector<int> note(n + 1);
	
	while(last_raw >= 1)
	{
		int first_raw = last_raw - 1;
		while(first_raw > L[k]) 
			first_raw--;
		
		for(int j = 0; j <= S; j++)
			T[0][j] = linha[k][j];

		for(int i = 1; i <= last_raw - first_raw; i++)
			for(int j = 0; j <= S; j++)
				if(j >= V[i + first_raw])
					T[i][j] = Min(T[i - 1][j], T[i - 1][j - V[i + first_raw]] + W[i + first_raw]);
				else
					T[i][j] = T[i - 1][j];
		
		for(int i = last_raw - first_raw; i > 0; i--)
			if(T[i][s] != T[i - 1][s])
			{
				note[ID[i + first_raw]] += W[i + first_raw];
				s -= V[i + first_raw];
			}
		
		last_raw = first_raw;
		k--;
	}
	
	int number_of_notes = 0;
	for(int &w : note)
		number_of_notes += w;
	
	cout << number_of_notes << '\n';
	
	for(int i = 1; i <= n; i++)
		cout << note[i] << ' ';
	puts("");


	return 0;
}
