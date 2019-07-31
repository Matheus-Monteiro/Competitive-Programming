#include <bits/stdc++.h>
#define INF -(1<<30)
typedef long long int lli;

using namespace std;

lli merge_sort(vector<lli> &v){
    lli inv = 0;
    
    if(v.size() == 1)
        return 0;
        
    vector<lli> u1, u2;
    
    for(int i = 0; i < v.size()/2; i++)
        u1.push_back(v[i]);
    for(int i = v.size()/2; i < v.size(); i++)
        u2.push_back(v[i]);
        
    inv += merge_sort(u1);
    inv += merge_sort(u2);
    
    u1.push_back(INF);
    u2.push_back(INF);
    
    int ini1 = 0, ini2 = 0;
    
    for(int i = 0; i < v.size(); i++){
        if(u1[ini1] > u2[ini2]){
            v[i] = u1[ini1];
            ini1++;
        }else{
            v[i] = u2[ini2];
            ini2++;
            inv += u1.size()-ini1-1;
        }
    }
    return inv;
}

int main(){
    vector<lli> v;
    lli n,inversoes, x, y;

    cin >> n;
    v.resize(n);
    for(auto &p : v){
        cin >> x >> y;
        p = (x*x)+(y*y);
    }
    inversoes = merge_sort(v);
    cout << inversoes << endl;
    return 0;
}