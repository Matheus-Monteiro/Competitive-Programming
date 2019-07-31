#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
typedef long long int lli;

using namespace std;

vector<lli> v;
lli k, aux;
int n;

int buscab(int x){
    int ini = 1, fim = n, meio, resp;
    
    while(ini <= fim){
        meio = (ini+fim)/2;
        
        if(v[x]+v[meio] == k)
            return meio;
        if(v[x]+v[meio] > k)
            fim = meio-1;
        if(v[x]+v[meio] < k)
            ini = meio+1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    
    v.pb(-1);
    for(int i = 1; i <= n; i++){
        cin >> aux;
        v.pb(aux);
    }
    
    cin >> k;
    
    int p1, p2;
    bool ok = true;
    for(int i = 1; i <= n and ok; i++){
        aux = buscab(i);
        if(aux != -1){
            p1 = i;
            p2 = aux;
            ok = false;
        }
    }
       
    cout << v[p1] << " " << v[p2] << endl;
    
    return 0;
}