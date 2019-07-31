#include <iostream>

using namespace std;

int main(){
    int n, s, v, menor;
    
    cin >> n >> s;
    menor = s;
    while(n--){
        cin >> v;
        s += v;
        if(s < menor)
            menor = s;
    }
    cout << menor << endl;
    return 0;
}