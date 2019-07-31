#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, ini, aux, cont;
    vector<int> v;
    bool ok;
    
    cin >> n;

    while(n--){
        cin >> aux;
        v.push_back(aux);
    }
    
    cont = 0;
    ok = 1;
    for(int i = 0; i < v.size()-1; i++){
        aux = v[i];
        while(v[i+1] > aux){
            if(v[i+1] <= aux+10)
                cont++;
            aux++;
        }
    }
    
    cout << cont+10 << endl;
    
    return 0;
}