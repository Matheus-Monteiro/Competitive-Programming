#include <iostream>

using namespace std;

int result=0;
int soma(int n, int one){
	if(one <= n){
		result += one;
		soma(n, one+1);	
	}
}

int main(){
	
	int n, one = 1;
	cin >> n;	
	
	soma(n, one);
	cout << result << endl;
	return 0;
}