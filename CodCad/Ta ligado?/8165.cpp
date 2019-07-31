#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int main(){
    vector< vector<int> > grafo;
    int n, m, t, a, b;
    bool buraco;
    
    cin >> n >> m;
    
    grafo.resize(n+2);
    
    while(m--){
    	buraco = false;
        cin >> t >> a >> b;
        if(t == 0){
            for(int i = 0; i < grafo[a].size(); i++){
				if(grafo[a][i] == b){
					buraco = true;
					break;
				}
			}
			if(!buraco){
				for(int i = 0; i < grafo[b].size(); i++){
					if(grafo[b][i] == a){
						buraco = true;
						break;
					}
			   	}
			}
			(buraco) ? cout << "1" << endl : cout << "0" << endl;
		}else{
    		grafo[a].push_back(b);
			grafo[b].push_back(a);
		}   
	}
    return 0;
} 