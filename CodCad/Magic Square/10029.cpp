#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

vector<int> v;
int m[15][15];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
   
    int n, l, c, dp, ds;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];
    dp = 0;
    ds = 0;
    for(int i = 0; i < n; i++){
        l = 0;
        c = 0;
        for(int j = 0; j < n; j++){
            l += m[i][j];
            c += m[j][i];
            
            if(i == j)
                dp += m[i][j];
            if(j+i == n-1)
                ds += m[i][j];
        }
        v.push_back(l);
        v.push_back(c);
    }
    v.push_back(dp);
    v.push_back(ds);   
    
    bool ok = true;
    int comp = v[0];
    for(int i = 1; i < v.size() and ok; i++)
        if(comp != v[i])
            ok = false;
    
    (ok) ? cout << comp << endl : cout << "-1" << endl;
       
    return 0;
}