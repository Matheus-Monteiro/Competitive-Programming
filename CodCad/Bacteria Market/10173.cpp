#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int x, n, bac;
    double qtd, maior, d, c;
    
    cin >> n;
    
    maior = bac = x = 0;
    while(n--){
        cin >> d >> c;
        qtd = c*log10(d);
        if(maior < qtd){
            maior = qtd;
            bac = x;
        }
        x++;
    }
    cout << bac << endl;
    
    return 0;
}