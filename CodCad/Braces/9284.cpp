#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

stack<char> pilha;
string str[1010];
bool ok;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k;
    cin >> k;
    cin.ignore();
    
    for(int i = 0; i < k; i++)
        getline(cin, str[i]);
  
    ok = true;
    for(int j = 0; j < k; j++){
        for(int i = 0; i < str[j].size() && ok; i++){
            if(str[j][i] == '{')
                pilha.push('{');
            else
                if(str[j][i] == '}'){
                    if(pilha.empty())
                        ok = false;
                    else
                        pilha.pop();    
                }
        }
    }
    
    if(!pilha.empty())
        ok = false;
        
    cout << (ok ? "S" : "N") << endl;
    
    return 0;
}