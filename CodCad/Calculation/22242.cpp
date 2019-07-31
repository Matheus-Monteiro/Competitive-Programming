#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int k = max(n, m);
    int v1[n], v2[m], r[k];

    for(int i = 0; i < n; i++) cin >> v1[i];
    for(int j = 0; j < m; j++) cin >> v2[j];

    for(int i = 0; i < k; i++){
        if(n > i and m > i)
            r[i] = v1[i] + v2[i];
        else
            if(n > i and m <= i)
                r[i] = v1[i];
            else
                if(n <= i and m > i)
                    r[i] = v2[i];
    }
    for(int i = k-1; i >= 0; i--)
        if(r[i] > 1){
            r[i] -= 2;
            r[i-1]++;
        }
    bool ok = true;
    for(int i = k-1; i >= 0 and ok; i--)
        if(r[i] == 0) r[i] = -1;
        else ok = false;
    for(int i = 0; i < k; i++)
        if(r[i] != -1)
            cout << r[i] << ' ';
    cout << '\n';

    return 0;
}