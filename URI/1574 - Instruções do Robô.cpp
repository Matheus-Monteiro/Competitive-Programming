// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Instruções do Robô
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1574

#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    int posicao, t, n;
    string str;
    
    cin >> t;
    
    while(t--){
        posicao = 0;
        cin >> n;
        cin.ignore();
        while(n--){
            getline(cin, str);
            if(str == "LEFT"){
                posicao--;
                v.push_back(-1);
            }else{
                if(str == "RIGHT"){
                    posicao++;
                    v.push_back(1);
                }else{
                    string aux;
                    bool ok = true;
                    for(int i = 0; i < str.size() and ok; i++)
                        if(isdigit(str[i])){
                            ok = false;
                            aux = str.substr(i, str.size());
                        }
                    int num = stoi(aux);
                    posicao += v[num-1];
                    v.push_back(v[num-1]);
                }
            }
        }
        cout << posicao << "\n";
        v.clear();
    }
    
    return  0;
}
