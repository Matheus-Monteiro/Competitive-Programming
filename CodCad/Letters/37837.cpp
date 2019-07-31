#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &v){
    vector<int> pilha;
    for(int i = 0; i < v.size(); i++){
        auto it = upper_bound(pilha.begin(), pilha.end(), v[i]);
        if(it == pilha.end())
            pilha.push_back(v[i]);
        else
            *it = v[i];
    }
    return pilha.size();
}

int main(){
    string s;
    vector<int> v;
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
        v.push_back(int(s[i]-'A'));
    cout << lis(v) << '\n';
    
    return 0;
}