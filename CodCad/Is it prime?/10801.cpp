#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    
    bool ok = true;
    if(n == 1)
        ok =false;
    for(unsigned long long i = 2; i < sqrt(n) and ok; i++){
        if(n%i == 0)
            ok = false;
    }
    
    (ok) ? cout << "S" << endl : cout << "N" << endl;

    return 0;
}