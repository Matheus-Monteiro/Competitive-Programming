#include <iostream>
#define endl '\n'

using namespace std;

int main(){     
    ios_base::sync_with_stdio(false); cin.tie(NULL);
  
    int a, b, c;
	
	cin >> a >> b >> c;
	
	if(a == b || a == c || b == c || a == b+c || b == a+c || c == b+a)
		cout << "S" << endl;
	else
		cout << "N" << endl;
        
    return 0;
}
