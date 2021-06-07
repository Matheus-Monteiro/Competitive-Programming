#include <bits/stdc++.h>
using namespace std;

// longest common substring

int pd[1000][1000];

int LCS(string a, string b)
{
    for(int i = 1; i <= a.size(); i++)
        for(int j = 1; j <= b.size(); j++)
            if(a[i-1] == b[j-1])
                pd[i][j] = pd[i-1][j-1] + 1;
            else
                pd[i][j] = max(pd[i][j-1], pd[i-1][j]);
    return pd[a.size()][b.size()];
}

int main()
{
    string a, b;

    cin >> a >> b;
    int lcs = LCS(a, b);
    
    cout << lcs << '\n';   
    cout << "Edit Distance: " << a.size()+b.size()-2*lcs << '\n';

    return 0;
}
