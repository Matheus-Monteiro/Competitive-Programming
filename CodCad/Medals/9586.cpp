#include <bits/stdc++.h>

using namespace std;

int v[3], p[3];

bool f(int a, int b){
    return v[a] < v[b];
}

int main(){     
    for(int i = 0; i < 3; i++){
        cin >> v[i];
        p[i] = i;
    }
    
    sort(p, p+3, f);
    
    for(int i = 0; i < 3; i++)
        cout << p[i]+1 << endl;
        
    return 0;
}
