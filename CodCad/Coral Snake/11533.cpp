#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    
    cin >> a >> b >> c >> d;
    
    if(b == d and b != a and b != c)
        cout << "V" << endl;
    else
        if(a == c and a != b and a != d)
            cout << "V" << endl;
        else
            cout << "F" << endl;

    return 0;
}