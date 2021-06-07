#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 100;
 
typedef long long ll;

#define ii pair<int, long long>
#define fi first
#define se second
 
ll A = 911382323, B = 972663749;
ll h[MAX], p[MAX];
string s;

ll buildP(int k)
{
    if(k == 0) 
        return p[0] = 1;
    return p[k] = (buildP(k - 1)*A) % B;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> s;
	buildP(s.size() + 10);
	
    int n = s.size();
    int sz = sqrt(n);
	
    unordered_set<ll> AAAA;
    vector<ii> BBBB;
	
	string aux;
	
    while(cin >> aux)	
	{
        long long value = 0, j = 0;
        while(j < aux.size())
        {
            if(j == 0) value = aux[j];
            else value = (value * A + aux[j]) % B;
            j++;
        }
        if(aux.size() > sz)
            BBBB.push_back({aux.size(), value});
        else
            AAAA.insert(value);
	}
    sort(BBBB.begin(), BBBB.end());	
	
	string ans;
    	
	int j = 0, i = 0;
    
	while(i < s.size())
	{
	    ans.push_back(s[i]);
	
	    if(j == 0) h[j] = s[i];
	    else h[j] = (h[j - 1] * A + s[i]) % B;
	    
	    int leng = -1;
	    long long vh;
	    
        for(int k = j; k >= 0 and k >= j - sz - 1 and leng < 0; k--)
        {
            if(k == 0) vh = h[j];
            else 
            {
                vh = (h[j] - h[k - 1] * p[j - k + 1]) % B;
                if(vh < 0) vh += B;
            }
            if(AAAA.count(vh))
                leng = j - k + 1;
            //length j - k + 1
        }
	    
	    if(leng == -1)
	    {
	        for(int k = 0; k < BBBB.size(); k++)
	        {
	            int a = j - BBBB[k].first + 1; 

                if(a < 0) break;
	            
	            if(a == 0) vh = h[j];
                else 
                {
                    vh = (h[j] - h[a - 1] * p[j - a + 1]) % B;
                    if(vh < 0) vh += B;
                }
                
                if(vh == BBBB[k].se)
                    leng = BBBB[k].fi;
                
	        }
	    }
	    if(leng != -1)
	    {
            j -= leng;
            while(leng--) ans.pop_back();	    
	    }
        ++j;
	    i++;
	}
    cout << ans << '\n';

 
    return 0;
}
