// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Estiagem
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1023

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<ii> v;

int main(){
	int n, a, b, qp, qc, city = 1;
	bool flag = false;
	
	while(cin >> n and n){
		if(flag) cout << '\n';
		else flag = true;
		qp = qc = 0;
		while(n--){
			cin >> a >> b;
			v.push_back({a, b/a});
			qp += a; qc += b;
		}
		sort(v.begin(), v.end(), [](ii a, ii b){return a.second < b.second;});
		cout << "Cidade# " << city++ << ':' << '\n';
		for(int i = 0; i < v.size(); i++){
		    if(i < v.size()-1 and v[i].second == v[i+1].second){
		        int h = v[i].first + v[i+1].first;
		        int c = v[i].second;
		        v[i+1] = {h, c};
		        
		    }else{
    			cout << v[i].first << '-' << v[i].second;
    			if(i != v.size()-1)
    				cout << ' ';
		    }        
	    }
		cout << '\n';
		double r = (double)qc/(double)qp;
		string str = to_string(r);
		cout << "Consumo medio: "; 
		for(int i = 0; i < str.size(); i++){
		    if(str[i] != '.')
		        cout << str[i];
	        else{
	            cout << '.';
	            if(i+1 < str.size()){
	                cout << str[i+1];
	                if(i+2 < str.size())
	                    cout << str[i+2];
                    else
                        cout << "0";
	            }else
	                cout << "00";
                break;
	        }
		    
		}
		cout << " m3." << '\n';
		v.clear();
	}
	
	return 0;
}
