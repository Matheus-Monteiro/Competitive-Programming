// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ordenação por Tamanho
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1244

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool comp(string a, string b){
    return a.size() > b.size(); 
}

int main(){
    vector<string> v;
    string str;
    int t;
    
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, str);
        istringstream iss(str);
        
        do{
            string sub;
            iss >> sub;
            if(iss)
                v.push_back(sub);
        }while(iss);
        
        stable_sort(v.begin(), v.end(), comp);
        
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
            if(i < v.size()-1)
                cout << " ";
        }
        cout << "\n";
        
        v.clear();
    }
    
    return 0;
}
