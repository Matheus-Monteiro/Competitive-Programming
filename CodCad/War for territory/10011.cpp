#include <iostream>
#define endl '\n'
const int MAXN = 1e6;

using namespace std;

int v[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, soma, metade, k;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
    soma = 0; 
    for(int i = 0; i < n; i++)
        soma += v[i];
    
    metade = soma/2;
    soma = 0;
    
    bool ok = true;
    for(int i = 0; i < n and ok; i++){
        soma += v[i];
        if(soma == metade){
            k = i;
            ok = false;
        }
    }
    k++;
    cout << k << endl;
    
    return 0;
}