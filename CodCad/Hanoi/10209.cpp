#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned long long int n, caso = 1, res;
    while(cin >> n and n != 0){
        res = pow(2,n)-1;
        cout << "Teste " << caso++ << endl << res << endl << endl;
    }
    return 0;
}