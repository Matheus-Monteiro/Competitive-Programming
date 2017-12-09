// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Carnaval
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2418

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<double> v;
	v.resize(5);
	for(double &p : v)
		cin >> p;
	sort(v.begin(), v.end());
	cout << fixed << setprecision(1) << v[1]+v[2]+v[3] << '\n';
	
    return 0;
}
