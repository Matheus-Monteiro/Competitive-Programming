#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int v[3];
    
    cin >> v[0] >> v[1] >> v[2];
    sort(v, v+3);
    if(v[0]+v[1] > v[2]){
        if((v[0]*v[0]+v[1]*v[1]) == v[2]*v[2])
            cout << "r" << "\n";
        else
            if((v[0]*v[0]+v[1]*v[1]) > v[2]*v[2])
                cout << "a" << "\n";
            else
                cout << "o" << "\n";    
    }else
        cout << "n" << "\n";
    
    
    return 0;
}