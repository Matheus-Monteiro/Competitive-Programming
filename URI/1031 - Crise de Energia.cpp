// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Crise de Energia
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1031

#include <bits/stdc++.h>
using namespace std;

bool josephus(deque<int> l, int k)
{
    int p = 0;
    while(l.size() != 1)
    {
        if(l[p] == 13)
            return false;
        l.erase(l.begin()+p);
        p = (p + k - 1) % l.size();
        
    }
    return true;
}

int main()
{
    int n;
    deque<int> l;
    
    while(cin >> n and n)
    {  
        for(int i = 1; i <= n; i++)
            l.push_back(i);
        int ans = -1;
        for(int i = 1; i <= n*n and ans == -1; i++)
            if(josephus(l, i))
                ans = i;            
        cout << ans << '\n';
        l.clear();
    }
    
    return 0;
}
