#include <bits/stdc++.h>

using namespace std;

int max_sum(vector<int> s){
    int resp = 0, maior = 0;
    for(int i = 0; i < s.size(); i++){
        maior = max(0, maior+s[i]);
        resp = max(resp, maior);
    }
    return resp;
}

int main(){
    vector<int> v;
    int n;
    
    cin >> n;
    v.resize(n);
    for(auto &p : v)
        cin >> p;
    int sum_max = max_sum(v);
    cout << sum_max << endl;   

    return 0;
}