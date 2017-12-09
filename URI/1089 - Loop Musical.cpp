// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Loop Musical
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1089

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
int arr[10005];

int main()
{
    while(cin >> n and n)
    {
        REP(i, n)
            cin >> arr[i];
        int ans = 0;
        FOR(i, 0, n)
        {
            bool fl = false;
            if(arr[i] > arr[i+1])
            {
                while(arr[i] > arr[i+1] and i < n-1)
                    i++, fl = true;
                if(i >= n-1) break;
            }
            else
            {
                while(arr[i] < arr[i+1] and i < n-1)
                    i++, fl = true;
                if(i >= n-1) break;
            }
            if(fl)
                i--;
            ans++;
        }
        if(arr[n-1] > arr[n-2] and arr[n-1] > arr[0] or arr[n-1] < arr[n-2] and arr[n-1] < arr[0])
            ans++;
        if(arr[0] > arr[1] and arr[0] > arr[n-1] or arr[0] < arr[1] and arr[0] < arr[n-1])
            ans++;
        cout << ans << '\n';
    }
    
	return 0;
}
