#include <iostream>

using namespace std;

struct time{
	int v, e, g, pontos;
}typedef t;

int main(){
	
	t c, f;
	
	cin >> c.v >> c.e >> c.g >> f.v >> f.e >> f.g;
	
	c.pontos = 3*c.v + c.e;
	f.pontos = 3*f.v + f.e;
	
	if(c.pontos > f.pontos)
		cout << "C" << endl;
	if(c.pontos < f.pontos)
		cout << "F" << endl;
	if(c.pontos == f.pontos){
		if(c.g > f.g)
			cout << "C" << endl;
		if(c.g < f.g)
			cout << "F" << endl;
		if(c.g == f.g)
			cout << "=" << endl;
	}
		
	return 0;
}