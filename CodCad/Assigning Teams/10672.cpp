#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
	return a < b;
}

int main(){
	int v[4], t1, t2;
	
	for(int i = 0; i < 4; i++)
		cin >> v[i];
		
	sort(v, v+4, comp);

	t1 = v[0] + v[3];
	t2 = v[1] + v[2];

	(t1 >= t2) ? cout << t1-t2 << endl : cout << t2-t1 << endl;

	return 0;
}