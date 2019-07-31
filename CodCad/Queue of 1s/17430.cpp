#include <bits/stdc++.h>

using namespace std;

int main(){
    bool ok = true, acabou = false;
    unsigned long long bitmask = 0LL;
    
    cin >> bitmask;
    if(!bitmask)
        acabou = true;

    for(long long i = 0; i < 64 and !acabou; i++){
        if(bitmask & (1LL<<i)){
            if(!ok)
                acabou = true;
        }else
            ok = false;
    }     
    cout << (!acabou ? 'S' : 'N') << '\n'; 
    
    return 0;
}