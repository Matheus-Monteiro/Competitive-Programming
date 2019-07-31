#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int n, num;
	bool ok, ok2;
	
	cin >> n;
	
	ok2 = true;
	for(int i = n; i > 1 and ok2; i--){
		ok = true;
		for(int j = 2; j < sqrt(i) and ok; j++){
			if(i%j == 0)
				ok = false;
		}
		if(ok){
			num = i;
			ok2 = false;
		}
	}
	cout << num << endl;

	return 0;
}