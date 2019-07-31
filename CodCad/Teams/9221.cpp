#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1100

using namespace std;

bool f(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

int main(){
    
    vector<pair<string, int> > jogadores;
    vector<string> times[MAX];
    string nome;
    int h, n, t;
    
    cin >> n >> t;
    
    for(int i = 0; i < n; i++){
        cin >> nome >> h;
        jogadores.push_back(make_pair(nome, h));
    }
    
    sort(jogadores.begin(), jogadores.end(), f);
    
    for(int j = 0, k = 0; j < n; j++){
        times[k].push_back(jogadores[j].first);
        k++;
        if(k == t)
            k = 0;
    }

    for(int i = 0; i < t; i++)
        sort(times[i].begin(), times[i].end());
    
    for(int i = 0; i < t; i++){
        cout << "Time " << i+1 << endl;
        for(int j = 0; j < times[i].size(); j++)
            cout << times[i][j] << endl;
        cout << endl;
    }
    
    return 0;
}