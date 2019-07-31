#include <iostream>
const int MAXN = 50;

using namespace std;

int main(){
    int b, n;
    int credito[MAXN];
    int d, c, v;
    
    while(cin >> b >> n and b != 0 or n != 0){
        for(int i = 0; i < b; i++)
            cin >> credito[i];
        while(n--){
            cin >> d >> c >> v;
            credito[c-1] += v;
            credito[d-1] -= v;
        }
        bool ok = true;
        for(int i = 0; i < b and ok; i++){
            if(credito[i] < 0)
                ok = false;
        }
        (ok) ? cout << "S" << endl : cout << "N" << endl;
    }
    return 0;
}