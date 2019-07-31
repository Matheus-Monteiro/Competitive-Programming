#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;

int main(){
    int n;
    cin >> n;
    bool ok;
    for(int i = n; i >= 2; i--){
        ok = true;
        for(int j = 2; j <= sqrt(i) and ok; j++)
            if(i%j == 0)
                ok = false;
        if(ok)
            v.push_back(i);
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size()-1)
            cout << " ";
    }
    cout << endl;
    return 0;
}