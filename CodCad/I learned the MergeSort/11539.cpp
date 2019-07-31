#include <bits/stdc++.h>
typedef long long int lli;

using namespace std;

int main(){
    vector<lli> v;
    int n;
    cin >> n;
    v.resize(n);
    for(auto &p : v)
        cin >> p;
    sort(v.begin(), v.end(), greater<lli>());
    int i = 0;
    for(auto &p : v){
        cout << p;
        if(i < v.size()-1)
            cout << " ";
        i++;
    }
    cout << endl;
    return 0;
}