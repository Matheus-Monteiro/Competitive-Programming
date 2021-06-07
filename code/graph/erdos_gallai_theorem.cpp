#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main()
{
	int n;
	while(~scanf(" %lld", &n))
	{
    	vector<int> degree(n), pref(n + 2);
        for(int &i : degree)
            scanf (" %lld", &i);
    	sort(degree.begin(), degree.end(), greater<int>());    
    	for(int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + degree[i];
        bool fl = true;
        if(pref[n] & 1)
            fl = false;
        int j = n;
        for(int k = 1; k <= n and fl; k++)
        {
            int L = pref[k];
            int R = k * (k - 1);
            while(j > 0 and degree[j - 1] < k)
                j--;
            int pos = max(j, k);
            R += pref[n] - pref[pos] + (pos - k) * k;
            if(L > R) fl = false;
        }
        puts(fl ? "possivel" : "impossivel");
	}
	return 0;
}
