#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	string str;
	
	cin >> str;
	
	char c = str[str.size()-1];
	int n = atoi(&c);
	
	if(n%2 == 0)   
		cout << "S" << endl;
	else
		cout << "N" << endl;
	int soma = 0;
	for(int i = 0; i < str.size(); i++){
		char a = str[i];
		int az = atoi(&a);
		soma += a;
	}
	
	if(soma%3 == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	if(n == 0 || n == 5)
		cout << "S" << endl;
	else
		cout << "N" << endl;
		
	return 0;
}