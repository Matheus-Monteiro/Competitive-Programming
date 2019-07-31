#include <iostream>
#include <vector>
#include <algorithm>
const int MAXN = 1e6;

using namespace std;

int v[MAXN];
int p[MAXN];
vector<int> rec;

bool comp(int a, int b){
    return v[a] < v[b];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        p[i] = i;
    }
    sort(p, p+n, comp);
    
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != v[p[i]]){
            cont++;
            rec.push_back(v[i]);
        }
    }
    sort(rec.begin(), rec.end());
    cout << cont << endl;
    if(!rec.empty()){  
        for(int i = 0; i < rec.size(); i++){
            cout << rec[i];
            if(i < rec.size()-1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}