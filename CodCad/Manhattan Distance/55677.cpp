#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c[4];
    
    cin >> c[0] >> c[1] >> c[2] >> c[3];
    cout << abs(c[0]-c[2]) + abs(c[1]-c[3]) << '\n';
        
	return 0;
}