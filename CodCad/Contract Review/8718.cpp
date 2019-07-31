#include <bits/stdc++.h>
#define MAX 1010

using namespace std;

int main(){
	
	string str, aux;
	char d;
	bool buraco;
	
	while(cin >> d >> str && d != '0' || str != "0"){
	
		int sz = str.size(), c;
		
		for(int i = 0; i < sz; i++)
			if(str[i] != d )
				aux.push_back(str[i]);
	
		c = 0;
		buraco = true;
		
		for(int i = 0; i < aux.size() && buraco; i++){
			if(aux[i] == '0')
				c++;
			else
				buraco = false;
		}
		if(c != 0)
		   	aux.erase(0, c-1);
		
		if(aux.size() == 0)
	 		aux.push_back('0');
		 
	    cout << aux << endl;
		
		aux.clear();
		str.clear();
	}	
	return 0;
}