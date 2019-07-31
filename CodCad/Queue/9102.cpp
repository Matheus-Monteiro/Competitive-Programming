#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> v;
    vector<int> s;
    int n, m, aux;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        v.push_back(aux);
    }

    cin >> m;
    
    for(int i = 0; i < m; i++){
        cin >> aux;
        s.push_back(aux);
    }
    bool loop;
    for(int i = 0; i < m; i++){
        aux = s[i];
        loop = true;
        for(int j = 0; j < v.size() && loop; j++){
            if(aux == v[j]){
                v.erase(v.begin()+j);
                loop = false;
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size()-1)
            cout << " ";
    }
    cout << endl;
        
    return 0;
}