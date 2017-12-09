// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ajude Seu Madruga
// Nível: 1
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1912

#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-4;
const int MAX = 1e5 + 20;

int n, a, num_max;
int v[MAX];

double solve(double x)
{
    double ans = 0.0;
    for(int i = 0; i < n; i++)
        if(v[i] > x)
            ans += v[i]-x;
    return ans;
}

double buscab()
{
    double b = 0.0, e = double(num_max), m;
    for(int i = 0; i < 200; i++)
    {
        m = (b+e)/2;
        double A = solve(m);
        if(fabs(A-a) < EPS)
            break;
        if(A > a)
            b = m;
        else
            e = m;       
    }
    return m;
}

int main()
{
    while(cin >> n >> a and (n or a))
    {   
        num_max = -1;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];    
            num_max = max(num_max, v[i]);
        }
        double a_total = solve(0.0);
        if(fabs(a_total - a) < EPS)
            cout << ":D" << '\n';
        else if(a > a_total)
            cout << "-.-" << '\n';
        else
            cout << setprecision(4) << fixed << buscab() << '\n';
    }
  
    return 0;
}
