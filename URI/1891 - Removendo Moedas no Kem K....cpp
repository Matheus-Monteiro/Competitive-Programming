// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Removendo Moedas no Kem K...
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1891

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

bool cor[MAX];
string str;

int main()
{
    int t, n;
    
    scanf("%d", &t);
    while(t--)
    {
        vector<int> v;
        scanf("%d", &n);
        char e[MAX];
        scanf("%s", e);
        str = string(e);
        REP(i, n)
            if(i >= 0 and !cor[i] and str[i] == 'D')
            {
                cor[i] = true;
                if(i > 0 and !cor[i-1]) str[i-1] = (str[i-1] == 'B' ? 'D' : 'B');
                if(i < n-1 and !cor[i+1]) str[i+1] = (str[i+1] == 'B' ? 'D' : 'B');
                v.push_back(i+1);
                i -= 2;
            }    
        bool fl = true;
        REP(i, str.size())
            if(str[i] == 'B')
                fl = false;
        if(fl)
        {
            printf("Y\n");
            fl = false;
            REP(i, v.size())
            {
                if(fl) printf(" ");
                else fl = true;
                printf("%d", v[i]);
            }
            printf("\n");
        }
        else
            printf("N\n");
        memset(cor, 0, sizeof(cor));
    }
   
	return 0;
}
