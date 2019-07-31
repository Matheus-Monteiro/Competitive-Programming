#include <iostream>
#include <algorithm>

using namespace std;

int v[3];

int main(){
    int valor;
    cin >> valor;
    
    for(int i = 0; i < 3; i++)
        cin >> v[i];    
    sort(v, v+3);
    int cont = 0;
    for(int i = 0; i < 3; i++){
        if(valor >= v[i]){
            cont++;
            valor -= v[i];
        }    
    }
    cout << cont << endl;
    return 0;
}