#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string str, aux;
	
	cin >> str;
	
	for(int i = 0; i < str.size(); i++){
		if(isdigit(str.at(i)) || str.at(i) == '-'){
			aux.push_back(str.at(i));
		}else{
				if(str.at(i) == 'A' || str.at(i) == 'B' || str.at(i) == 'C') 
					aux.push_back('2');
					
				if(str.at(i) == 'D' || str.at(i) == 'E' || str.at(i) == 'F')
					aux.push_back('3');
				
				if(str.at(i) == 'G' || str.at(i) == 'H' || str.at(i) == 'I') 
					aux.push_back('4');
					
				if(str.at(i) == 'J' || str.at(i) == 'K' || str.at(i) == 'L')
					aux.push_back('5');
					
				if(str.at(i) == 'M' || str.at(i) == 'N' || str.at(i) == 'O')
					aux.push_back('6');
					
				if(str.at(i) == 'P' || str.at(i) == 'Q' || str.at(i) == 'R' || str.at(i) == 'S')
					aux.push_back('7');
					
				if(str.at(i) == 'T' || str.at(i) == 'V' || str.at(i) == 'U') 
					aux.push_back('8');
					
				if(str.at(i) == 'W' || str.at(i) == 'X' || str.at(i) == 'Y' || str.at(i) == 'Z') 
					aux.push_back('9');
			}
	}
	
	cout << aux << endl;
	
	return 0;
}