#include <bits/stdc++.h>

using namespace std;

int main(){
    int c = 0;
    unsigned long long bitmask = 0LL;
    
    cin >> bitmask;
    
    for(long long i = 0; i < 64; i++)
        if(bitmask & (1LL<<i))
            c++;
    cout << c << '\n';
    
    return 0;
}