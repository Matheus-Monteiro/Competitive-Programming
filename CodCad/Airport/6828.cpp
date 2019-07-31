#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, v, x, y, maior, caso = 1;
    vector< vector<int> > grafo;
    vector<int> resposta;
    vector<int> pos;

    while((cin >> v >> a) && v != 0 || a != 0){
    
        grafo.resize(v);

        for(int i = 0; i < a; i++){
            cin >> x >> y;
            grafo[x-1].push_back(y-1);
        }
        int tam_aux;
        for(int i = 0; i < v; i++){
            tam_aux = grafo[i].size();
            resposta.push_back(tam_aux);
        }
        int cont;
        
        for(int i = 0; i < v; i++){
            cont = 0;
            for(int j = 0; j < v; j++){
                int sz = grafo[j].size();
                for(int k = 0; k < sz; k++){
                    if(grafo[j][k] == i)
                        cont++;
                }
            }
            resposta[i] += cont;
        }
        maior = 0;
        int aux;
        for(int i = 0; i < resposta.size(); i++){
            if(maior < resposta[i]){
                maior = resposta[i];
                aux = i + 1;
            }
        }
        pos.push_back(aux);
        resposta[aux-1] = 0;
        
        for(int i = 0; i < resposta.size(); i++){
            if(maior == resposta[i]){
                aux = i + 1;
                pos.push_back(aux);
            }
        }
        sort(pos.begin(), pos.end());
        
        cout << "Teste " << caso << endl;
        
        for(int i = 0; i < pos.size(); i++){
            cout << pos[i];
            if(i < pos.size()-1)
                cout << " ";
        }
        cout << endl << endl;
        caso++;
        resposta.clear();
        pos.clear();
        grafo.clear();
    }
    
    return 0;
}