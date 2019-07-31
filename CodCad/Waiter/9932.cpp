#include <iostream>

using namespace std;

int main(){
    int n, c, l , cont = 0;
    
    cin >> n;
    
    while(n--){
        cin >> l >> c;
        if(l > c)
            cont += c;
    }
    cout << cont << endl;
    return 0;
}