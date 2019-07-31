#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	
	cin >> str;
	
	char aux;
	int soma = 0;
	bool ok = true;
	for(int i = str.size()-1; i >= 0; i--){
		aux = str[i];
		if(ok){
			soma += atoi(&aux);
			ok = false;
		}else{
			soma += 10*atoi(&aux);
			ok = true;
		}	
	}
	if(soma%11 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
			
	
	return 0;
}
