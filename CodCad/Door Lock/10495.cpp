#include <iostream>
#include <cmath>

using namespace std;

int v[1010], n, m;

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int cont = 0;
    for(int i = 1; i < n; i++){
        if(m >= v[i-1])
            v[i] += m - v[i-1];
        else
            v[i] -= v[i-1] - m;
            
        cont += fabs(m - v[i-1]);        
    }   
    cout << cont << endl;
    
    return 0;
}