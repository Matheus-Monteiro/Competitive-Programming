#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int lps[2*MAX+5];
char s[MAX];

int manacher()
{
    int n = strlen(s);
    string p(2*n+3, '#');
    p[0] = '^';
    for(int i = 0; i < n; i++)
        p[2*(i+1)] = s[i];
    p[2*n+2] = '$';
    int k = 0, r = 0, m = 0;
    int l = p.length();
    for(int i = 1; i < l; i++)
    {
        int o = 2*k - i;
        lps[i] = (r > i) ? min(r-i, lps[o]) : 0;
        while(p[i + 1 + lps[i]] == p[i - 1 - lps[i]])
            lps[i]++;
        if(i + lps[i] > r) k = i, r = i + lps[i];
        m = max(m, lps[i]);
    }
    /*for(int i = 1; i <= 2 * n + 1; i++)
        cout << lps[i] << ' ';
    puts("");*/
    return m;
}

int main()
{	
    cin >> s;
    cout << manacher() << '\n';
	return 0;
}