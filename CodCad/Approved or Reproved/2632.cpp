	#include <iostream>

	using namespace std;

	int main(){

		double a, b, media;
		
		cin >> a >> b;
		
		media = (a+b)/2;
		
		if(media >= 7)
			cout << "Aprovado" << endl;
		else
			if(media < 7 && media >= 4)
				cout << "Recuperacao" << endl;
			else 
				cout << "Reprovado" << endl;
		
		return 0;
	}