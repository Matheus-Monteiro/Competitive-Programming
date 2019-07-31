#include <bits/stdc++.h>
#define endl '\n'
const double PI = 3.1415;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int L, A, P, R;
	double d, p;
		
	cin >> L >> A >> P >> R;
		
	d = sqrt(A*A + L*L + P*P);
	
	if(d <= 2*R)
		cout << "S" << endl;
	else
		cout << "N" << endl; 
		
	return 0;
}