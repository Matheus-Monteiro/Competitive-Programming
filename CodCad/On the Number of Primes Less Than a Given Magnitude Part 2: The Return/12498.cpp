#include <bits/stdc++.h>

using namespace std;

int e_composto[10000010];

void crivo(int n){
    e_composto[1] = 1;
    for(int i = 2; i <= n; i++)
        if(!e_composto[i])
            for(int j = 2; i*j <= n; j++)
                e_composto[i*j] = 1;
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    
    cin >> n;
    
    crivo(n);
    
    for(int i = 1; i <= n; i++){
        if(!e_composto[i]){
            cout << i;
            if(i < n)
               cout << " ";
        }
    }
    cout << "\n";
    
    return 0;
}