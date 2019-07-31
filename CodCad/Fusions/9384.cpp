#include <iostream>
#define MAXN 100100

using namespace std;

int pai[MAXN];

int find(int x){
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    pai[find(x)] = find(y);
}

int main(){
    int n, k;
    char l;
    int banco1, banco2;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
        pai[i] = i;
    
    while(k--){
        cin >> l >> banco1 >> banco2;
        
        if(l == 'F')
            join(banco1, banco2);
        else
            if(find(banco1) == find(banco2))
                cout << "S" << endl;
            else
                cout << "N" << endl;
    }
  
    return 0;
}   