#include <iostream>
#include <set>

using namespace std;

int main(){
    
    set<int> registro;
    int n, aux, r;
    
    cin >> n;
    
    while(n--){
        cin >> aux;
        registro.insert(aux);
    }
    
    r = registro.size();
    
    cout << r << endl;
    
    return 0;
}
