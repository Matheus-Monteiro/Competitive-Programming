// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Lenda de Flavious Josephus
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1030

#include <bits/stdc++.h>
using namespace std;

int josephus(deque<int> &l, int k)
{
    int p = 0;
    while(l.size() != 1)
    {
        p = (p + k - 1) % l.size();
        l.erase(l.begin()+p);
    }
    return l[0];
}

int main()
{
    int t, n, k, c = 1;
    deque<int> l;

    cin >> t;
    
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            l.push_back(i);
        cout << "Case " << c++ << ": " << josephus(l, k) << '\n';
        l.clear();
    }

    return 0;
}
