#include <bits/stdc++.h>

using namespace std;

int main(){
    
    double v[5];
    
    for(int i = 0; i < 5; i++)
        cin >> v[i];
    
    sort(v, v+5);
    
    double nota = v[1] + v[2] + v[3];
    
    cout.precision(1);
    cout << fixed;
    cout << nota << endl;
        
    return 0;
}
