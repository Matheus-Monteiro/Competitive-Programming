#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int troco(int valor, vector<int> moeda){
	int aux = 0, qtd = 0;
	
	for(int i = 0; i < moeda.size(); i++){
		aux = valor/moeda[i];
		valor -= aux*moeda[i];
		qtd += aux;
	}
	return qtd;
}

int main(){ 
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	
	vector<int> moeda;
	moeda.push_back(100);
	moeda.push_back(50);
	moeda.push_back(25);
	moeda.push_back(10);
	moeda.push_back(5);
	moeda.push_back(1);
	
	cin >> n;
	
	cout << troco(n, moeda) << endl;

	return 0;
}