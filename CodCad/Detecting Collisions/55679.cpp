#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f[4], s[4];
    bool fl = true;    
    
    cin >> f[0] >> f[1] >> f[2] >> f[3];
    cin >> s[0] >> s[1] >> s[2] >> s[3];

    if(f[0] > s[0] and f[0] > s[2])
        fl = false;
    else if(f[1] > s[1] and f[1] > s[3])
        fl = false;
    else if(s[0] > f[0] and s[0] > f[2])
        fl = false;
    else if(s[1] > f[1] and s[1] > f[3])
        fl = false;
        
    cout << fl << '\n';
        
	return 0;
}