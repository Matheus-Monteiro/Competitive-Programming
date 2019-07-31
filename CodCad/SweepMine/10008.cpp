#include <iostream>
const int MAXN = 55;

using namespace std;

int v[MAXN];
int res[MAXN];

int main(){
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    if(v[0] == 1)
        res[0]++;
    if(v[1] == 1)
        res[0]++;
    
    for(int i = 1; i < n-1; i++){
        if(v[i-1] == 1)
            res[i]++;
        if(v[i+1] == 1)
            res[i]++;
        if(v[i] == 1)
            res[i]++;
    }
    
    if(v[n-2] == 1)
        res[n-1]++;
    if(v[n-1] == 1)
        res[n-1]++;
    
    for(int i = 0; i < n; i++)
        cout << res[i] << endl;
    
    return 0;
}