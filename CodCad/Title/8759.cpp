#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string title(string F){
	F[0] = toupper(F[0]);
	for(int i = 1; i < F.size(); i++){
		if(F[i] == ' ')
	   	   	F[i+1] = toupper(F[i+1]);
		else
			if(isupper(F[i]) && F[i-1] != ' ')
		   		F[i] = tolower(F[i]);
	}
	return F;
}

int main(){ 
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	string F;

	getline(cin, F);

	cout<< title(F) << endl;
}