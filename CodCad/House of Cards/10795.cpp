#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    pair<int,int>v[n];
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    for(int i=0;i<n;i++){
        v[i].first=(v[i].second)%m;
    }
    sort(v, v+n);
    for(int i=0;i<n;i++){
        cout<<v[n-1-i].second<<" ";
    }
   
}