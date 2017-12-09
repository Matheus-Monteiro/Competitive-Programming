// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: URI
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1787

#include <bits/stdc++.h>
using namespace std;

int aux[] = {-1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824 
};

bool buscab(int x){
    int b = 1, e = 31, m;
    while(b <= e){
        m = (b+e)/2;
        if(aux[m] == x)
            return true;
        if(aux[m] > x)
            e = m-1;
        if(aux[m] < x)
            b = m+1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, p[3];
    long long v[3];
    bool ok1, ok2, ok3;
    
    while(cin >> n and n){
        memset(p, 0, sizeof(p));
        while(n--){
            ok1 = ok2 = ok3 = false;
            
            cin >> v[0] >> v[1] >> v[2];
            
            ok1 = buscab(v[0]);
            ok2 = buscab(v[1]);
            ok3 = buscab(v[2]);
            
            if(ok1 and v[0] > v[1] and v[0] > v[2]) p[0]+=2;
            else if(ok1) p[0]++;
            if(ok2 and v[1] > v[0] and v[1] > v[2]) p[1]+=2;
            else if(ok2) p[1]++;
            if(ok3 and v[2] > v[0] and v[2] > v[1]) p[2]+=2;
            else if(ok3) p[2]++;
        }
        if(p[0] > p[1] and p[0] > p[2]) cout << "Uilton" << '\n';
        else if(p[1] > p[0] and p[1] > p[2]) cout << "Rita" << '\n';
        else if(p[2] > p[0] and p[2] > p[1]) cout << "Ingred" << '\n';
        else cout << "URI" << '\n';
    }

    return 0;
}
